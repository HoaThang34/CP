import os
import random
import subprocess
import string

PROBLEM_NAME = "KHOANGCACH"
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
EXE_PATH = os.path.join(SCRIPT_DIR, "CODE_AC", f"{PROBLEM_NAME}.exe")
TEST_DIR = os.path.join(SCRIPT_DIR, "TEST")

def generate_input(test_id):
    # Subtasks
    # 50%: Q=1, N < 10^3
    # 20%: Q=1
    # 20%: N <= 10
    # 10%: No extra
    
    # Text says: "50% Q=1, N<10^3", "20% Q=1", "20% N<=10?", "10% free".
    
    S_str = ""
    Q_queries = []
    
    if test_id <= 1:
        S_str = "abcyzz" # Example
        Q_queries = [(1, 3), (2, 5), (5, 6)]
        
    elif test_id <= 10: # Subtask 1
        N = random.randint(10, 999)
        S_str = "".join(random.choices(string.ascii_lowercase, k=N))
        Q_queries = [(1, N)]
        
    elif test_id <= 14: # Subtask 2
        N = random.randint(1000, 100000)
        S_str = "".join(random.choices(string.ascii_lowercase, k=N))
        Q_queries = [(1, N)]
        
    elif test_id <= 18: # Subtask 3 (N <= 10?? Weird)
        # Maybe "N <= 10^5" typo in text but let's assume N small for many queries?
        # Text says "20% N <= 10". Really small string.
        N = random.randint(1, 10)
        S_str = "".join(random.choices(string.ascii_lowercase, k=N))
        Q = random.randint(1, 100000)
        for _ in range(Q):
            L = random.randint(1, N)
            R = random.randint(L, N)
            Q_queries.append((L, R))
            
    else: # Subtask 4
        N = random.randint(50000, 100000)
        S_str = "".join(random.choices(string.ascii_lowercase, k=N))
        Q = random.randint(50000, 100000)
        for _ in range(Q):
            L = random.randint(1, N)
            R = random.randint(L, N)
            Q_queries.append((L, R))

    return S_str, Q_queries

def main():
    if not os.path.exists(TEST_DIR):
        os.makedirs(TEST_DIR)

    for i in range(1, 21):
        test_name = f"test{i:02d}"
        test_path = os.path.join(TEST_DIR, test_name)
        if not os.path.exists(test_path):
            os.makedirs(test_path)
        
        S_str, Q_queries = generate_input(i)
        
        with open(os.path.join(test_path, f"{PROBLEM_NAME}.INP"), "w") as f:
            f.write(f"{S_str}\n")
            f.write(f"{len(Q_queries)}\n")
            for l, r in Q_queries:
                f.write(f"{l} {r}\n")
            
        print(f"Running {test_name}...")
        subprocess.run([EXE_PATH], cwd=test_path, check=True)

if __name__ == "__main__":
    main()
