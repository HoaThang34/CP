import os
import random
import subprocess
import shutil

PROBLEM_NAME = "XOADOAN"
PROBLEM_NAME = "XOADOAN"
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
EXE_PATH = os.path.join(SCRIPT_DIR, "CODE_AC", f"{PROBLEM_NAME}.exe")
TEST_DIR = os.path.join(SCRIPT_DIR, "TEST")

def generate_input(test_id):
    # Determine subtask based on test_id
    # Total 20 tests
    # 01-08: Subtask 1 (40%) N < 100, Ai > 0
    # 09-12: Subtask 2 (20%) N <= 5000, Ai <= 0
    # 13-16: Subtask 3 (20%) N <= 10^5, Ai > 0 (Wait, 20% Ai > 0, general N?)
    # 17-20: Subtask 4 (20%) N <= 10^5, Arbitrary Ai
    
    # Correction: The text says:
    # 40% N < 100, Ai > 0
    # 20% N <= 5000, Ai <= 0
    # 20% Ai > 0 (Implies N up to 10^5)
    # 20% Free
    
    N = 0
    S = 0
    A = []
    
    if 1 <= test_id <= 8:
        N = random.randint(1, 99)
        # Ai > 0. Let's say up to 1000.
        A = [random.randint(1, 1000) for _ in range(N)]
        # S can be anything. Random from -100 to Sum.
        total = sum(A)
        S = random.randint(-100, total + 100)
    elif 9 <= test_id <= 12:
        N = random.randint(100, 5000)
        # Ai <= 0.
        A = [random.randint(-1000, 0) for _ in range(N)]
        # S around sum or 0 or positive.
        total = sum(A)
        S = random.randint(total - 1000, 100)
    elif 13 <= test_id <= 16:
        N = random.randint(5000, 100000)
        # Ai > 0.
        A = [random.randint(1, 10**9) for _ in range(N)]
        total = sum(A)
        S = random.randint(0, total // 2) # Force removal likely
    else: # 17-20
        N = random.randint(5000, 100000)
        # Ai arbitrary
        A = [random.randint(-10**9, 10**9) for _ in range(N)]
        S = random.randint(-10**14, 10**14)

    # Corner Cases explicit logic override
    if test_id == 1:
        N = 1; A = [10]; S = 5 # Expect 1
    if test_id == 2:
        N = 1; A = [10]; S = 10 # Expect 0
    if test_id == 9:
        # All neg, S=0. Sum <= 0 <= S. Expect 0.
        N = 10; A = [-1]*10; S = 0

    return N, S, A

def main():
    if not os.path.exists(TEST_DIR):
        os.makedirs(TEST_DIR)

    for i in range(1, 21):
        test_name = f"test{i:02d}"
        test_path = os.path.join(TEST_DIR, test_name)
        if not os.path.exists(test_path):
            os.makedirs(test_path)
        
        N, S, A = generate_input(i)
        
        inp_file = os.path.join(test_path, f"{PROBLEM_NAME}.INP")
        with open(inp_file, "w") as f:
            f.write(f"{N}\n")
            # Format array carefully usually space separated
            # Text description says: "Dòng thứ hai chứa N số nguyên".
            # "Dòng thứ ba chứa S".
            # Wait, let's check input format in PDF text.
            # "Dòng đầu tiên chứa ... N"
            # "Dòng thứ hai chứa N số nguyên"
            # "Dòng thứ ba chứa số nguyên S"
            # Wait, verify example.
            # Example 1:
            # 3
            # 4 -5 4
            # 3
            # Matches.
            
            f.write(" ".join(map(str, A)) + "\n")
            f.write(f"{S}\n")
            
        # Run AC Code
        # We run inside the test directory so it picks up .INP and writes .OUT
        cmd = [EXE_PATH]
        # On windows execute .exe
        
        print(f"Running {test_name}...")
        subprocess.run(cmd, cwd=test_path, check=True)

if __name__ == "__main__":
    main()
