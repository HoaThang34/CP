import os
import random
import subprocess

PROBLEM_NAME = "CHOXUAN"
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
EXE_PATH = os.path.join(SCRIPT_DIR, "CODE_AC", f"{PROBLEM_NAME}.exe")
TEST_DIR = os.path.join(SCRIPT_DIR, "TEST")

def generate_input(test_id):
    # Determine subtask
    # Usually straightforward for this simple problem.
    # 20 tests.
    
    # Text says: N < 10^9 (approx). K <= 10^?
    # Let's assume standard constraints.
    
    N = 0
    K = 0
    
    if test_id <= 2: # Examples / Small
        if test_id == 1: N = 1000000; K = 50000
        if test_id == 2: N = 350000; K = 50000
    
    elif test_id <= 10: # Sufficient funds
        N = random.randint(100, 10**9)
        # Ensure K is small enough
        K = random.randint(1, N // 8)
        
    elif test_id <= 15: # Insufficient funds
        K = random.randint(1, 10**8)
        # Ensure N < 7*K
        needed = K * 7
        N = random.randint(1, needed - 1)
        
    else: # Edge cases
        if test_id == 16: # Exact
            K = 123456
            N = K * 7
        elif test_id == 17: # Almost exact (1 less)
            K = 100000
            N = K * 7 - 1
        elif test_id == 18: # Zero K? (Prices usually > 0, but handle min)
            K = 0
            N = 100
        elif test_id == 19: # Large limits
            N = 10**18 # Check long long handling
            K = 10**9 
        else: # Random
            N = random.randint(1, 10**14)
            K = random.randint(1, 10**9)
            
    return N, K

def main():
    if not os.path.exists(TEST_DIR):
        os.makedirs(TEST_DIR)

    for i in range(1, 21):
        test_name = f"test{i:02d}"
        test_path = os.path.join(TEST_DIR, test_name)
        if not os.path.exists(test_path):
            os.makedirs(test_path)
        
        N, K = generate_input(i)
        
        with open(os.path.join(test_path, f"{PROBLEM_NAME}.INP"), "w") as f:
            f.write(f"{N}\n{K}\n")
            
        subprocess.run([EXE_PATH], cwd=test_path, check=True)
        print(f"Generated {test_name}")

if __name__ == "__main__":
    main()
