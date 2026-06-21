#include <bits/stdc++.h>
using namespace std;
#define task "sol"
const int N = 100005;
const int Q = 1000005;
long long n, q;
vector<long long> a;
void subtask1(){
    long long l, r;
    cin >> l >> r;
    set<long long> st;
    for(long long i = l; i <= r; i++){
        st.insert(a[i]);
    }
    cout << st.size() << endl;
}
int bit[N], last[Q];
struct Query{
    int l, r, id;
};
Query qr[Q];
int ans[Q];
void update(int i,int v){
    while(i <= n){
        bit[i] += v;
        i += i & -i;
    }
}
int get(int i){
    int s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i;b
    }
    return s;
}
bool cmp(Query x, Query y){
    return x.r < y.r;
}
void subtask2(){
    for(int i = 0; i < q; i++){
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(qr, qr + q, cmp);
    int R = 0;
    for(int i = 0; i < q; i++){
        while(R < qr[i].r){
            R++;
            int x = a[R];
            if(last[x]) update(last[x], -1);
            update(R, 1);
            last[x] = R;
        }
        ans[qr[i].id] = get(qr[i].r) - get(qr[i].l - 1);
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

    cin >> n;
    a.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> q;
    if(n <= 1000 && q <= 1000) {
        while(q--){
            subtask1();
        }
    } else {
        subtask2();
    }
    return 0;
}
