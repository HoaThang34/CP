import os
import shutil

ROOT_DIR = r"c:\Users\Admin\Desktop\DE HSG TP HA NOI 2026 THCS"
PROBLEMS = ['BANSUNG', 'CANBANG', 'CHOXUAN', 'KHOANGCACH', 'XOADOAN']
DEST_DIR = os.path.join(ROOT_DIR, "TEST CHUNG")

def copy_tests():
    if not os.path.exists(DEST_DIR):
        os.makedirs(DEST_DIR)
        print(f"Created {DEST_DIR}")

    for problem in PROBLEMS:
        src_test_path = os.path.join(ROOT_DIR, problem, "TEST")
        dest_test_path = os.path.join(DEST_DIR, problem)

        if os.path.exists(src_test_path):
            print(f"Copying {src_test_path} to {dest_test_path}...")
            if os.path.exists(dest_test_path):
                shutil.rmtree(dest_test_path) # Clean before copying to ensure exact copy
            shutil.copytree(src_test_path, dest_test_path)
            print(f"Div copied: {problem}")
        else:
            print(f"WARNING: Source not found for {problem}")

if __name__ == "__main__":
    copy_tests()
