# Hướng dẫn Code Mẫu

Thư mục này chứa các code C++ AC cho từng bài toán. Mỗi file code bao gồm tất cả các subtask được phân chia bằng **namespace**.

## Cấu trúc Code

Mỗi file `.cpp` thường có cấu trúc:

- `namespace Subtask1`: Giải thuật cho subtask nhỏ (thường brute force hoặc giải thuật đơn giản).
- `namespace Full`: Giải thuật tối ưu cho toàn bộ bài toán.
- `main()`: Kiểm tra giới hạn đầu vào (N, K, ...) để gọi namespace phù hợp (hoặc gọi Full nếu nó tối ưu cả trường hợp nhỏ).

## Danh sách bài toán

1. **DAYBIAN (DAYBIAN.cpp)**

   - Subtask 1 (N <= 2000): O(N²).
   - Full (N <= 200,000): O(N log N) dùng Prefix Sum + Map.
2. **MATTHU (MATTHU.cpp)**

   - Subtask 1 (N, M <= 1000): O(NM) cập nhật trực tiếp.
   - Full (N, M <= 100,000): O(M log N) Segment Tree + Tối ưu Modulo.
3. **THUTHACH (THUTHACH.cpp)**

   - Subtask 1 (K nhỏ): Duyệt tuyến tính.
   - Full (K <= 10^9): Tìm kiếm nhị phân kết hợp LCM.
4. **HOPQUA (HOPQUA.cpp)**

   - Chỉ sử dụng một giải thuật tối ưu chung (Full) vì giải thuật Tham lam + Sắp xếp (O(N log N)) chạy tốt cho mọi subtask.
