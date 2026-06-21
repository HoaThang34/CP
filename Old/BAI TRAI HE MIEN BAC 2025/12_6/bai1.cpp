#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
ll n, a, b; 
vell arr;
ll xuli1(ll a, ll b){
    return a||b;
    
}
void sub1(){
    cin >> n >> a >> b;
    arr.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll d = 0;
    vell c;
    ll i = 0; 
    while (a != b){
        d++;
        a = a | arr[i];
        i++;
        if (i >= n) i = 0;
        c.push_back(i);
    } 

    cout << d << endl;
    for (ll x : c) cout << x << " ";

}
void solve(){
    cin >> n >> a >> b;
    arr.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    queue<pair<ll, vell>> q;
    set<ll> vs;
    q.push({a, {}});
    vs.insert(a);
    for (int st = 0; st <= 100 && !q.empty(); ++st) {
        int sz = q.size();
        while (sz--) {
            auto [cur, pth] = q.front(); q.pop();
            if (cur == b) {
                cout << (ll)pth.size() << endl;
                for (ll x : pth) cout << x << " ";
                cout << endl;
                return;
            }
            for (ll i = 0; i < n; ++i) {
                ll nxt = cur | arr[i];
                if (!vs.count(nxt)) {
                    vs.insert(nxt);
                    vell np = pth;
                    np.push_back(i+1);
                    q.push({nxt, np});
                }
            }
        }
    }
    cout << -1 << endl;
}
ll solve1(){
    cin >> n >> a >> b;
    arr.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (a == b) {
        cout << 0 << endl;
        return 0;
    }
    ll cnt = 0;
    ll cur = a;
    vell res;
    set<ll> vs;
    vs.insert(cur);
    while(cnt <= 101 && cur != b){
        int cl = -1, cnt_b = 64; 
        for(ll i = 0; i < n; ++i){
            if((arr[i] & (b ^ cur)) == 0) continue;
            ll nxt = cur | arr[i];
            if (vs.count(nxt)) continue;
            ll f = nxt ^ b;
            int pop = __builtin_popcountll(f);
            if(pop < cnt_b){
                cnt_b = pop;
                cl = i;
            }
        }
        if(cl == -1) break;
        cnt++;
        cur |= arr[cl];
        res.push_back(cl+1);
        vs.insert(cur);
    }
    if(cur != b) {
        cout << -1 << endl;
        return -1;
    }
    cout << cnt << endl;
    for(ll x : res) cout << x << " ";
    cout << endl;
    return cnt;
}
void solve2(){
    cin >> n >> a >> b;
    arr.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll cnt = 0;
    vell res;
    set<ll> vs;
    const int bit = 64;
    auto MASK = [](int i) { return 1LL << i; };
    auto flip = [&](ll x) {
        ll bn = 0;
        for (int i = 0; i < bit; ++i) {
            bn += ((x >> i) & 1) ? 0 : MASK(i);
        }
        return bn;
    };
    ll cur = a;
    while(cnt <= 101 && cur != b){
        int cl = -1, cnt_b = 64;
        bool used_flip = false;
        ll best_nxt = cur;
        for(ll i = 0; i < n; ++i){
            // Không đảo bit
            ll nxt = cur | arr[i];
            if (!vs.count(nxt)) {
                ll f = nxt ^ b;
                int pop = __builtin_popcountll(f);
                if(pop < cnt_b && (arr[i] & (b ^ cur))) {
                    cnt_b = pop;
                    cl = i;
                    used_flip = false;
                    best_nxt = nxt;
                }
            }
            // Đảo bit
            ll flipped = flip(arr[i]);
            nxt = cur | flipped;
            if (!vs.count(nxt)) {
                ll f = nxt ^ b;
                int pop = __builtin_popcountll(f);
                if(pop < cnt_b && (flipped & (b ^ cur))) {
                    cnt_b = pop;
                    cl = i;
                    used_flip = true;
                    best_nxt = nxt;
                }
            }
        }
        if(cl == -1) break;
        cnt++;
        res.push_back(cl + 1);
        cur = best_nxt;
        vs.insert(cur);
        // Nếu muốn in ra thao tác đảo bit, có thể thêm 1 vector<bool> để lưu used_flip
    }
    if(cur != b) {
        cout << -1 << endl;
        return;
    }
    cout << cnt << endl;
    for(ll x : res) cout << x << " ";
    cout << endl;
}
#define task "sol"
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    // sub1();
    // solve();
    // solve1();
    solve2();
    return 0;
}