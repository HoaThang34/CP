import os
import random
import subprocess

PROBLEM_NAME = "CANBANG"
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
EXE_PATH = os.path.join(SCRIPT_DIR, "CODE_AC", f"{PROBLEM_NAME}.exe")
TEST_DIR = os.path.join(SCRIPT_DIR, "TEST")

def generate_input(test_id):
    # Determine subtask
    # Subtasks described in text:
    # 70%: K=1, N < 10^3, 0 < A_i <= 10^5
    # 20%: K=1, 0 <= A_i <= 10^9
    # 10%: No constraint (K arbitrary?)
    
    N = 0
    K = 0
    A = []
    
    if test_id <= 2: # Examples
        if test_id == 1:
            N = 6; K = 1
            A = [4, 1, 7, 8, 5, 6] # Output: 3 (5: 4,6; 6: 5,7; 7: 6,8? wait. 5-1=4, 5+1=6. Yes. 6-1=5, 6+1=7. 7-1=6, 7+1=8. 8 not present? 8 is present. distinct? "4 1 7 8 5 6". Sorted: 1 4 5 6 7 8.
            # 5: need 4,6. Have 4,6. OK.
            # 6: need 5,7. Have 5,7. OK.
            # 7: need 6,8. Have 6,8. OK.
            # Answer 3.
            
        elif test_id == 2:
            N = 6; K = 2
            A = [4, -1, 7, 8, 5, 6] # Check negative
            # Distinct? Text said distinct.
    
    elif test_id <= 12: # 70% Subtask 1
        N = random.randint(10, 1000)
        K = 1
        # Generate A_i <= 10^5 distinct
        # Use random.sample if range large enough
        A = random.sample(range(1, 100001), N)
        
    elif test_id <= 16: # 20% Subtask 2
        N = random.randint(1000, 100000)
        K = 1
        # A_i up to 10^9
        # To get matches, we should construct some
        start = random.randint(1, 10**8)
        A = [start + i for i in range(N)] # Consequetive sequence ensures many matches with K=1
        random.shuffle(A)
        
    else: # 10% Subtask 3
        N = random.randint(1000, 100000)
        K = random.randint(1, 1000)
        # Construct to have some matches
        # Generate half random, half derived
        base = random.sample(range(1, 10**9), N // 2)
        derived = [x + K for x in base]
        A = base + derived
        A = list(set(A)) # Ensure distinct
        # Fill rest
        while len(A) < N:
            A.append(random.randint(1, 10**9))
            A = list(set(A))
        A = A[:N]
        random.shuffle(A)
        
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
