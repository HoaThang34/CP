#include <bits/stdc++.h>
using namespace std;
void make_set(int v) {
    parent[v] = v; // Tạo ra cây mới có gốc là đỉnh v
}

int find_set(int v) {
    if (v == parent[v]) return v; // Trả về đỉnh v nếu như đỉnh v là gốc của cây
    return find_set(parent[v]); // Đệ quy lên cha của đỉnh v
}

void union_sets(int a, int b) {
    a = find_set(a); // Tìm gốc của cây có chứa đỉnh a
    b = find_set(b); // Tìm gốc của cây có chứa đỉnh b
    if (a != b) parent[b] = a; // Gộp hai cây nếu như hai phần tử ở hai cây khác nhau
}
#define task "sol"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  
  return 0;
}
