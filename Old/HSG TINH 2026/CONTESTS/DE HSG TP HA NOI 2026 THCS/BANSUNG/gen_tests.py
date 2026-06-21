import os
import random
import subprocess

PROBLEM_NAME = "BANSUNG"
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
EXE_PATH = os.path.join(SCRIPT_DIR, "CODE_AC", f"{PROBLEM_NAME}.exe")
TEST_DIR = os.path.join(SCRIPT_DIR, "TEST")

def generate_input(test_id):
    # Subtasks
    # 30%: N, K < 30, A_i < 30
    # 20%: K=1
    # 30%: N < 1000
    # 20%: Unconstrained
    
    N = 0
    K = 0
    A = []
    
    if test_id <= 1:
        # Example
        N = 6; K = 3
        A = [6, 7, 1, 3, 2, 1]
    
    elif test_id <= 7: # Subtask 1
        N = random.randint(1, 29)
        K = random.randint(1, 29)
        A = [random.randint(1, 29) for _ in range(N)]
        
    elif test_id <= 11: # Subtask 2 (K=1)
        N = random.randint(100, 1000)
        K = 1
        A = [random.randint(1, 10**6) for _ in range(N)]
        
    elif test_id <= 17: # Subtask 3
        N = random.randint(100, 1000)
        K = random.randint(1, N) # reasonable K
        A = [random.randint(1, 10**9) for _ in range(N)]
        
    else: # Subtask 4
        N = random.randint(1000, 200000) # Full N
        K = random.randint(1, 10) # Full K is small (<= 10 in PDF)
        # PDF says "N <= 2*10^5; K <= 10". Important.
        # So K is always small.
        A = [random.randint(1, 10**9) for _ in range(N)]
        
    return N, K, A

def main():
    if not os.path.exists(TEST_DIR):
        os.makedirs(TEST_DIR)

    for i in range(1, 21):
        test_name = f"test{i:02d}"
        test_path = os.path.join(TEST_DIR, test_name)
        if not os.path.exists(test_path):
            os.makedirs(test_path)
        
        N, K, A = generate_input(i)
        
        with open(os.path.join(test_path, f"{PROBLEM_NAME}.INP"), "w") as f:
            f.write(f"{N} {K}\n")
            f.write(" ".join(map(str, A)) + "\n")
            
        subprocess.run([EXE_PATH], cwd=test_path, check=True)
        print(f"Generated {test_name}")

if __name__ == "__main__":
    main()
