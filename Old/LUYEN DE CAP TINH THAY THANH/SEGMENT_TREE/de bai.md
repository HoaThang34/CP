**Bài 1: Tìm tổng đoạn (Range Sum Query) - SEGM1.**

Cho một mảng số nguyên **$A$** gồm **$n$** phần tử, hãy xây dựng **Segment Tree** để hỗ trợ:

1. **Cập nhật:** Thay đổi giá trị của một phần tử tại vị trí **$i$**.
2. **Truy vấn:** Tìm tổng các phần tử trong đoạn **$[L, R]$**.

#### **Dữ liệu vào:**

* Dòng 1: Số nguyên **$n$** (**$1 \le n \le 10^5$**) – số phần tử của mảng.
* Dòng 2: **$n$** số nguyên **$A[i]$** (**$|A[i]| \le 10^9$**).
* Dòng 3: Số nguyên **$q$** – số lượng truy vấn.
* **$q$** dòng tiếp theo, mỗi dòng có dạng:
  * `1 i v` (Cập nhật **$A[i] = v$**)
  * `2 L R` (Tìm tổng đoạn **$[L, R]$**)

#### **Dữ liệu ra:**

* Với mỗi truy vấn `2 L R`, in ra tổng các phần tử trong đoạn **$[L, R]$**.

#### **Ví dụ:**

**Input:**

```
5
3 5 7 9 11
3
2 1 3
1 1 10
2 1 3
```

**Output:**

```
15
22
```

#### **Giải thích:**

* `2 1 3`: Tìm tổng đoạn **$[1, 3] \rightarrow 3 + 5 + 7 = 15$**.
* `1 1 10`: Cập nhật **$A[1] = 10$**.
* `2 1 3`: Tổng mới đoạn **$[1, 3] \rightarrow 10 + 5 + 7 = 22$**.

## Bài 2: Tìm min/max trên đoạn (Range Min/Max Query) - SEGM2.

Cho mảng **$A$**, hãy xây dựng **Segment Tree** để hỗ trợ:

1. **Cập nhật:** Thay đổi một phần tử.
2. **Truy vấn:** Tìm giá trị nhỏ nhất trên đoạn **$[L, R]$**.

### Dữ liệu vào:

* **Dòng 1:** **$n, q$** – số phần tử của mảng và số truy vấn.
* **Dòng 2:** **$n$** số nguyên **$A[i]$**.
* **$q$ dòng tiếp theo** có dạng:
  * `1 i v`: Cập nhật **$A[i] = v$**.
  * `2 L R`: Tìm giá trị nhỏ nhất trên đoạn **$[L, R]$**.

### Dữ liệu ra:

* Với mỗi truy vấn `2 L R`, in ra **min** trong đoạn **$[L, R]$**.

### Ví dụ:

**Input**

**Plaintext**

```
6
4 2 7 3 9 1
3
2 1 4
1 3 0
2 1 4
```

**Output**

**Plaintext**

```
2
0
```

### Giải thích:

* `2 1 4`: Min trên **$[1, 4] \rightarrow \min(4, 2, 7, 3) = 2$**.
* `1 3 0`: Cập nhật **$A[3] = 0$**.
* `2 1 4`: Min mới trên **$[1, 4] \rightarrow \min(4, 2, 0, 3) = 0$**.

## Bài 3: Đếm số phần tử lớn hơn X trên đoạn - SEGM3

Cho mảng **$A$**, hãy đếm số phần tử **lớn hơn X** trong đoạn **$[L, R]$**.

### Dữ liệu vào:

* **Dòng 1:** **$n$**.
* **Dòng 2:** **$n$** số nguyên **$A[i]$**.
* **Dòng 3:** số **$q$**.
* **$q$ dòng tiếp theo** có dạng:
  * `"1 i v"` (Cập nhật **$A[i] = v$**).
  * `"2 L R X"` (Đếm số phần tử **$> X$** trong đoạn **$[L, R]$**).

### Dữ liệu ra:

* Với mỗi truy vấn `"2 L R X"`, in ra số phần tử **$> X$**.

### Ví dụ:

**Input**

**Plaintext**

```
5
1 5 2 8 3
3
2 1 4 4
1 2 6
2 1 4 4
```

**Output**

**Plaintext**

```
2
3
```

**Giải thích:**

* `2 1 4 4`: Đếm số phần tử **$> 4$** trong **$[1, 4] \rightarrow \{5, 8\} \rightarrow 2$**.
* `1 2 6`: Cập nhật **$A[2] = 6$**.
* `2 1 4 4`: **$\{6, 8, 2\} \rightarrow 3$** (Số phần tử **$> 4$** lúc này là **$\{6, 8, 3\}$** trong đoạn **$[1, 4]$** tương ứng giá trị mảng là **$1, 6, 2, 8$**).

## Bài 4: Đếm số lần xuất hiện của X trên đoạn - SEGM4

Hãy đếm số lần xuất hiện của một số **$X$** trong đoạn **$[L, R]$**.

### Dữ liệu vào:

* **Dòng 1:** **$n, q$**.
* **Dòng 2:** **$n$** số nguyên **$A[i]$**.
* **$q$ dòng tiếp theo** có dạng:
  * `"1 i v"` (Cập nhật **$A[i] = v$**).
  * `"2 L R X"` (Đếm số lần xuất hiện của **$X$** trong đoạn **$[L, R]$**).

### Dữ liệu ra:

* Với mỗi truy vấn `"2 L R X"`, in ra số lần xuất hiện.

### Ví dụ:

**Input**

**Plaintext**

```
6
1 3 1 2 1 3
3
2 1 4 1
1 2 1
2 1 4 1
```

**Output**

**Plaintext**

```
2
3
```

**Giải thích:**

* `2 1 4 1`: **$\{1, 3, 1, 2\} \rightarrow$** số lần xuất hiện **$1 = 2$**.
* `1 2 1`: Cập nhật **$A[2] = 1$**.
* `2 1 4 1`: **$\{1, 1, 1, 2\} \rightarrow 3$**.

### **Bài 5: XOR trên đoạn (Range XOR Query) - SEGM5.**

Hãy tính XOR của tất cả các phần tử trong đoạn **$[L, R]$** sau mỗi lần cập nhật.

#### **Dữ liệu vào:**

* Dòng 1: **$n, q$**.
* Dòng 2: **$n$** số nguyên **$A[i]$**.
* **$q$** dòng tiếp theo có dạng:
  * `"1 i v"` (Cập nhật **$A[i] = v$**).
  * `"2 L R"` (Tính XOR đoạn **$[L, R]$**).

#### **Dữ liệu ra:**

* Với mỗi truy vấn `"2 L R"`, in ra XOR trên đoạn **$[L, R]$**.

#### **Ví dụ:**

**Input:**

**Plaintext**

```
5
1 2 3 4 5
2
2 1 3
1 2 6
2 1 3
```

**Output:**

**Plaintext**

```
0
7
```

#### **Giải thích:**

* `2 1 3`: **$1 \oplus 2 \oplus 3 = 0$**
* `1 2 6`: Cập nhật **$A[2] = 6$**
* `2 1 3`: **$1 \oplus 6 \oplus 3 = 7$**
* 


### **Bài 6: Tìm phần tử lớn thứ K trong đoạn - SEGM6.**

Cho một mảng A, hãy tìm phần tử **lớn thứ K** trong đoạn **$[L, R]$** sau mỗi lần cập nhật.

#### **Dữ liệu vào:**

* Dòng 1: **$n, q$** – số phần tử của mảng và số truy vấn.
* Dòng 2: **$n$** số nguyên **$A[i]$**.
* **$q$** dòng tiếp theo có dạng:
  * `"1 i v"` (Cập nhật **$A[i] = v$**).
  * `"2 L R K"` (Tìm phần tử lớn thứ K trong đoạn **$[L, R]$**).

#### **Dữ liệu ra:**

* Với mỗi truy vấn `"2 L R K"`, in ra phần tử lớn thứ K trong đoạn **$[L, R]$**.

#### Ví dụ:

Input

**Plaintext**

```
6
10 3 8 7 9 12
2
2 1 5 2
1 3 11
2 1 5 2
```

**Output**

**Plaintext**

```
10
11
```

#### **Giải thích:**

* `2 1 5 2`: Phần tử lớn thứ 2 trong **$[1, 5] \rightarrow \{10, 9, 8, 7\} \rightarrow 10$**
* `1 3 11`: Cập nhật **$A[3] = 11$**
* `2 1 5 2`: **$\{11, 10, 9, 7\} \rightarrow 11$**



### **Bài 7: Tìm phần tử nhỏ nhất lớn hơn hoặc bằng X trên đoạn - SEGM7.**

Hãy tìm phần tử nhỏ nhất **$\ge X$** trong đoạn **$[L, R]$**.

#### **Dữ liệu vào:**

* Dòng 1: **$n, q$**.
* Dòng 2: **$n$** số nguyên **$A[i]$**.
* **$q$** dòng tiếp theo có dạng:
  * `"1 i v"` (Cập nhật **$A[i] = v$**).
  * `"2 L R X"` (Tìm phần tử nhỏ nhất **$\ge X$** trong đoạn **$[L, R]$**).

#### **Dữ liệu ra:**

* Với mỗi truy vấn `"2 L R X"`, in ra phần tử nhỏ nhất **$\ge X$** hoặc -1 nếu không tìm thấy.

#### Ví dụ:

Input

**Plaintext**

```
6
2 5 8 1 7 3
3
2 1 5 6
1 3 10
2 1 5 6
```

**Output**

**Plaintext**

```
7
10
```

#### **Giải thích:**

* `2 1 5 6`: **$\{2, 5, 8, 1, 7\} \rightarrow$** phần tử nhỏ nhất **$\ge 6$** là 7
* `1 3 10`: Cập nhật **$A[3] = 10$**
* `2 1 5 6`: **$\{2, 5, 10, 1, 7\} \rightarrow$** phần tử nhỏ nhất **$\ge 6$** là 10






### **Bài 8: Đếm số phần tử trong khoảng [X, Y] trên đoạn - SEGM8.**

Hãy đếm số phần tử nằm trong khoảng **$[X, Y]$** trên đoạn **$[L, R]$**.

#### **Dữ liệu vào:**

* **Dòng 1:** **$n, q$**.
* **Dòng 2:** **$n$** số nguyên **$A[i]$**.
* **$q$ dòng tiếp theo** có dạng:
  * `"1 i v"` (Cập nhật **$A[i] = v$**).
  * `"2 L R X Y"` (Đếm số phần tử trong đoạn **$[L, R]$** nằm trong **$[X, Y]$**).

#### **Dữ liệu ra:**

* Với mỗi truy vấn `"2 L R X Y"`, in ra số lượng phần tử thỏa mãn điều kiện.

#### **Ví dụ:**

**Input**

**Plaintext**

```
5
2 4 7 1 6
3
2 1 5 3 6
1 2 8
2 1 5 3 6
```

**Output**

**Plaintext**

```
2
3
```

**Giải thích:**

* `2 1 5 3 6`: Các số trong đoạn **$[1, 5]$** nằm trong **$[3, 6]$** là **$\{4, 6\} \rightarrow 2$**.
* `1 2 8`: Cập nhật **$A[2] = 8$**.
* `2 1 5 3 6`: Các số lúc này là **$\{2, 8, 7, 1, 6\}$**. Các số trong **$[3, 6]$** là **$\{6\} \rightarrow 1$**.




### **Bài 9: Kiểm tra mảng con có phải dãy tăng dần không - SEGM9.**

Hãy kiểm tra xem đoạn **$[L, R]$** của mảng có phải là **dãy tăng dần** không.

#### **Dữ liệu vào:**

* **Dòng 1:** **$n, q$**.
* **Dòng 2:** **$n$** số nguyên **$A[i]$**.
* **$q$ dòng tiếp theo** có dạng:
  * `"1 i v"` (Cập nhật **$A[i] = v$**).
  * `"2 L R"` (Kiểm tra **$[L, R]$** có tăng dần không).

#### **Dữ liệu ra:**

* Với mỗi truy vấn `"2 L R"`, in "YES" nếu tăng dần, "NO" nếu không.

#### **Ví dụ:**

**Input**

**Plaintext**

```
5
1 2 3 4 5
3
2 1 5
1 3 1
2 1 5
```

**Output**

**Plaintext**

```
YES
NO
```

**Giải thích:**

* `2 1 5`: **$\{1, 2, 3, 4, 5\}$** là dãy tăng **$\rightarrow$** "YES".
* `1 3 1`: Cập nhật **$A[3] = 1$**.
* `2 1 5`: **$\{1, 2, 1, 4, 5\}$** không tăng **$\rightarrow$** "NO".




### **Bài 10: XOR trên đoạn (Range XOR Query) - SEGM10.**

Hãy tính XOR của tất cả các phần tử trong đoạn **$[L, R]$** sau mỗi lần cập nhật.

#### **Dữ liệu vào:**

* **Dòng 1:** **$n, q$**.
* **Dòng 2:** **$n$** số nguyên **$A[i]$**.
* **$q$ dòng tiếp theo** có dạng:
  * `"1 i v"` (Cập nhật **$A[i] = v$**).
  * `"2 L R"` (Tính XOR đoạn **$[L, R]$**).

#### **Dữ liệu ra:**

* Với mỗi truy vấn `"2 L R"`, in ra giá trị XOR trên đoạn **$[L, R]$**.

#### **Ví dụ:**

**Input**

**Plaintext**

```
5
1 2 3 4 5
2
2 1 3
1 2 6
2 1 3
```

**Output**

**Plaintext**

```
0
7
```

**Giải thích:**

* `2 1 3`: **$1 \oplus 2 \oplus 3 = 0$**.
* `1 2 6`: Cập nhật **$A[2] = 6$**.
* `2 1 3`: **$1 \oplus 6 \oplus 3 = 7$**.
