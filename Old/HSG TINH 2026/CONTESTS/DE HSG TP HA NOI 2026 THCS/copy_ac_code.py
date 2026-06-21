import os
import shutil

ROOT_DIR = r"c:\Users\Admin\Desktop\DE HSG TP HA NOI 2026 THCS"
PROBLEMS = ['BANSUNG', 'CANBANG', 'CHOXUAN', 'KHOANGCACH', 'XOADOAN']
DEST_DIR = os.path.join(ROOT_DIR, "BAI HS", "CODE MAU")

def copy_ac_code():
    if not os.path.exists(DEST_DIR):
        os.makedirs(DEST_DIR)
        print(f"Created {DEST_DIR}")

    for problem in PROBLEMS:
        src_file = os.path.join(ROOT_DIR, problem, "CODE_AC", f"{problem}.cpp")
        dest_file = os.path.join(DEST_DIR, f"{problem}.cpp")

        if os.path.exists(src_file):
            print(f"Copying {src_file} to {dest_file}...")
            shutil.copy2(src_file, dest_file)
            print(f"Copied: {problem}.cpp")
        else:
            print(f"WARNING: Source file not found: {src_file}")

if __name__ == "__main__":
    copy_ac_code()
