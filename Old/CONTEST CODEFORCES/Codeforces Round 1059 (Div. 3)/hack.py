# Python script: tìm test gây WA (tự sinh + brute-force)
# Lưu file thành find_wa.py và chạy: python3 find_wa.py
# Yêu cầu: nếu bạn có chương trình C++ candidate, biên dịch thành ./cand và script sẽ chạy ./cand < in.txt
# Nếu không có ./cand, script vẫn in test tìm được để bạn chạy thủ công.

import random, itertools, subprocess, sys, os, time

def brute_answer(n, a, segs):
    # với n nhỏ: duyệt mọi hoán vị (1..n) - permutation của a (giá trị) theo yêu cầu đề
    # Tính cho mỗi x in 1..n: có tồn tại hoán vị a' sao cho for all seg f(a',x,l,r)=1
    # Hàm f: 1 nếu (x - min(segment))*(x - max(segment)) < 0; tức x nằm giữa min và max (strict)
    # Ta kiểm tra: có hoán vị a' sao cho for all segs : min < x < max (strict)
    # Equivalent: for every segment, min(segment) < x < max(segment)
    # Điều kiện với permutation a' chỉ thay đổi vị trí giá trị, nhưng min/max trên segment là min/max của các giá trị
    # trong segment. Vì permutation phân phối các giá trị cho vị trí, ta cần cho mỗi segment có ít nhất
    # một giá trị < x và một giá trị > x trong segment.
    # Brute-force: thử mọi hoán vị của a (lần lượt gán cho positions 1..n) và kiểm tra.
    ans = ['0'] * n
    perms = set(itertools.permutations(a))
    for x in range(1, n+1):
        okx = False
        for p in perms:
            good = True
            for (l,r) in segs:
                mn = min(p[l-1:r])
                mx = max(p[l-1:r])
                if not ((x - mn) * (x - mx) < 0):
                    good = False
                    break
            if good:
                okx = True
                break
        ans[x-1] = '1' if okx else '0'
    return ''.join(ans)

def run_candidate(input_str):
    # chạy chương trình candidate ./cand nếu có, ngược lại return None
    if not os.path.isfile("./cand"):
        return None
    try:
        p = subprocess.Popen(["./cand"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        out,err = p.communicate(input_str, timeout=2)
        return out.strip().splitlines()
    except Exception as e:
        return None

def gen_random_case(max_n=7):
    # sinh test nhỏ (để brute-force khả thi).
    n = random.randint(2, max_n)
    m = random.randint(0, min(8, n*(n-1)//2))
    a = [random.randint(1, n) for _ in range(n)]
    segs = []
    for _ in range(m):
        l = random.randint(1,n)
        r = random.randint(1,n)
        if l>r: l,r = r,l
        segs.append((l,r))
    # build input text
    lines = []
    lines.append("1")
    lines.append(f"{n} {m}")
    lines.append(" ".join(map(str,a)))
    for (l,r) in segs:
        lines.append(f"{l} {r}")
    return "\n".join(lines) + "\n", n, a, segs

def main():
    random.seed(int(time.time()))
    tries = 20000
    for it in range(tries):
        inp, n, a, segs = gen_random_case(7)
        correct = brute_answer(n, a, segs)
        cand_out_lines = run_candidate(inp)
        if cand_out_lines is None:
            # không có candidate binary, in test và đáp án đúng để bạn dùng
            print("Không tìm thấy ./cand — in test tìm được (dùng làm hack hoặc để chạy candidate của bạn):")
            print("===INPUT===")
            print(inp, end="")
            print("===CORRECT OUTPUT===")
            print(correct)
            return
        # candidate có thể in nhiều dòng (tuy nhiên với 1 testcase nên 1 dòng)
        cand = cand_out_lines[0].strip() if len(cand_out_lines)>0 else ""
        if cand != correct:
            print("Tìm được test gây WA!")
            print("===INPUT===")
            print(inp, end="")
            print("===CORRECT OUTPUT===")
            print(correct)
            print("===CANDIDATE OUTPUT===")
            print(cand)
            return
    print("Không tìm thấy WA trong", tries, "test nhỏ ngẫu nhiên. Bạn có thể tăng tries hoặc max_n để tìm test mạnh hơn.")

if __name__ == '__main__':
    main()
