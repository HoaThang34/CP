/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""

struct D{
    long long n;
    vector<long long> p;
    vector<long long> r;
    void init(long long m){
        n = m;
        p.resize(n + 1);
        r.resize(n + 1);
        for(long long i = 0; i <= n; i++) p[i] = i;
        for(long long i = 0; i <= n; i++) r[i] = 0;
    }
    long long f(long long x){
        while(p[x] != x){
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    long long u(long long a, long long b){
        a = f(a);
        b = f(b);
        if(a == b) return 0;
        if(r[a] < r[b]){
            long long t = a;
            a = b;
            b = t;
        }
        p[b] = a;
        if(r[a] == r[b]) r[a]++;
        return 1;
    }
};

struct DS{
    unordered_map<long long,long long> p;
    unordered_map<long long,long long> r;
    long long g(long long x){
        unordered_map<long long,long long>::iterator it = p.find(x);
        if(it == p.end()){
            p[x] = x;
            r[x] = 0;
            return x;
        }
        while(p[x] != x){
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    long long j(long long a,long long b){
        a = g(a);
        b = g(b);
        if(a == b) return 0;
        if(r[a] < r[b]){
            long long t = a;
            a = b;
            b = t;
        }
        p[b] = a;
        if(r[a] == r[b]) r[a]++;
        return 1;
    }
};

long long n_, m_, k_;
vector<long long> U, V, W, ID;
vector<long long> res;

void sub1(){
    D d;
    d.init(n_);
    long long s = 0;
    for(int i = 1; i <= (int)m_; i++){
        long long e = ID[i];
        if(d.u(U[e], V[e])) s += W[e];
    }
    res.resize((size_t)k_);
    for(int i = 0; i < (int)k_; i++){
        if(i == 0) res[i] = s;
        else res[i] = 0;
    }
}

void sub2(){
    long long L = k_ < m_ ? k_ : m_;
    vector<D> d;
    d.resize((size_t)L);
    for(int t = 0; t < (int)L; t++) d[t].init(n_);
    vector<long long> s, cnt, full;
    s.resize((size_t)L);
    cnt.resize((size_t)L);
    full.resize((size_t)L);
    for(int t = 0; t < (int)L; t++){
        s[t] = 0;
        cnt[t] = 0;
        full[t] = 0;
    }
    for(int i = 1; i <= (int)m_; i++){
        long long e = ID[i];
        for(int t = 0; t < (int)L; t++){
            if(full[t]) continue;
            if(d[t].u(U[e], V[e])){
                s[t] += W[e];
                cnt[t]++;
                if(cnt[t] == n_ - 1) full[t] = 1;
                break;
            }
        }
    }
    res.resize((size_t)k_);
    for(int i = 0; i < (int)k_; i++){
        if(i < (int)L) res[i] = s[i];
        else res[i] = 0;
    }
}

void sub3(){
    vector<long long> cur, nxt;
    cur.resize(m_ + 1);
    for(int i = 1; i <= (int)m_; i++) cur[i] = ID[i];
    res.resize((size_t)k_);
    for(int i = 0; i < (int)k_; i++) res[i] = 0;
    long long rds = k_ < m_ ? k_ : m_;
    for(int r = 0; r < (int)rds; r++){
        D d;
        d.init(n_);
        long long s = 0;
        long long c = 0;
        nxt.clear();
        nxt.push_back(0);
        for(int i = 1; i < (int)cur.size(); i++){
            long long e = cur[i];
            if(d.u(U[e], V[e])){
                s += W[e];
                c++;
                if(c == n_ - 1) continue;
            }else{
                nxt.push_back(e);
            }
        }
        res[r] = s;
        if(c == 0) break;
        cur.swap(nxt);
        if((int)cur.size() <= 1) break;
    }
}

void sub4(){
    long long L = k_ < m_ ? k_ : m_;
    vector<DS> d;
    d.resize((size_t)L);
    vector<long long> s, cnt, full;
    s.resize((size_t)L);
    cnt.resize((size_t)L);
    full.resize((size_t)L);
    for(int t = 0; t < (int)L; t++){
        s[t] = 0;
        cnt[t] = 0;
        full[t] = 0;
    }
    unordered_map<unsigned long long,long long> last;
    last.reserve((size_t)m_);
    for(int i = 1; i <= (int)m_; i++){
        long long e = ID[i];
        long long x = U[e];
        long long y = V[e];
        if(x > y){
            long long t = x;
            x = y;
            y = t;
        }
        unsigned long long key = ((unsigned long long)x << 32) ^ (unsigned long long)y;
        long long start = 0;
        unordered_map<unsigned long long,long long>::iterator it = last.find(key);
        if(it != last.end()) start = it->second;
        for(int t = (int)start; t < (int)L; t++){
            if(full[t]) continue;
            if(d[t].j(U[e], V[e])){
                s[t] += W[e];
                cnt[t]++;
                if(cnt[t] == n_ - 1) full[t] = 1;
                last[key] = (long long)(t + 1);
                break;
            }
        }
    }
    res.resize((size_t)k_);
    for(int i = 0; i < (int)k_; i++){
        if(i < (int)L) res[i] = s[i];
        else res[i] = 0;
    }
}

void hoathang(){
    cin >> n_ >> m_ >> k_;
    U.resize(m_ + 1);
    V.resize(m_ + 1);
    W.resize(m_ + 1);
    ID.resize(m_ + 1);
    for(int i = 1; i <= (int)m_; i++){
        long long x, y, w;
        cin >> x >> y >> w;
        U[i] = x;
        V[i] = y;
        W[i] = w;
        ID[i] = i;
    }
    if(n_ <= 1){
        res.resize((size_t)k_);
        for(int i = 0; i < (int)k_; i++) res[i] = 0;
        for(int i = 0; i < (int)k_; i++) cout << res[i] << endl;
        return;
    }
    sort(ID.begin() + 1, ID.begin() + m_ + 1, [&](const long long &x, const long long &y){
        return W[x] > W[y];
    });
    if(k_ == 1){
        sub1();
    }else{
        long long L = k_ < m_ ? k_ : m_;
        if(n_ >= 5000 || L <= 200){
            sub2();
        }else if(n_ <= 2000 && m_ / (L == 0 ? 1 : L) >= 200){
            sub3();
        }else{
            sub4();
        }
    }
    for(int i = 0; i < (int)k_; i++) cout << res[i] << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t = 1;
    while (t--){
        hoathang();
    }
    return 0;
}
