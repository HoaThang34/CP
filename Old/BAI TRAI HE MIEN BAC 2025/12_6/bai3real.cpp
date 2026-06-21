#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 4e18; 
const int B = 60; 

struct Node{
    Node* c[2];
    Node(){
        c[0] = c[1] = nullptr;
    }
};

void add(Node* rt, ll val){
    Node* cur = rt;
    for (int i = B; i >= 0; --i){
        int b = (val >> i) & 1;
        if (cur->c[b] == nullptr){
            cur->c[b] = new Node();
        }
        cur = cur->c[b];
    }
}

ll get(Node* rt, ll val){
    Node* cur = rt;
    ll res = 0;
    for (int i = B; i >= 0; --i){
        int b = (val >> i) & 1;
        if (cur->c[b] != nullptr){
            cur = cur->c[b];
        } else if (cur->c[1-b] != nullptr){
            cur = cur->c[1-b];
            res |= (1LL << i);
        } else {
            return INF; 
        }
    }
    return res;
}

void del(Node* rt){
    if (!rt) return;
    del(rt->c[0]);
    del(rt->c[1]);
    delete rt;
}

ll n, k; 
vector<ll> a;


void solve(){
    vector<ll> v;
    for (ll l = 0; l < n; ++l){
        Node* rt = new Node();
        ll cur_min_xor = INF;

        if (l + 1 < n){ 
            add(rt, a[l]);
        } else { 
            del(rt);
            continue;
        }

        for (ll r = l + 1; r < n; ++r){ 
            
            ll xor_val = get(rt, a[r]); 
            
            cur_min_xor = min(cur_min_xor, xor_val);
            
            if (cur_min_xor != INF){
                v.push_back(cur_min_xor);
            }
            
             add(rt, a[r]);
        }
        del(rt);
    }
    
    sort(v.begin(), v.end());
    
    if (k > 0 && k <= (long long)v.size()){
        cout << v[k - 1] << endl;
    } 
}

// #define task "sol"
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    
    a.resize(n);
    for (ll i = 0; i < n; ++i){
        cin >> a[i];
    }

    if (n < 2){ 
        return 0; 
    }
    
    solve(); 
    
    return 0;
}