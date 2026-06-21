#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
#define task "sol"
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin>>s;
    int n=s.length();
    int mx=0;

    if (n == 0){
        cout << 0 << endl;
        return 0;
    }
    for(char d = '0'; d <= '9'; ++d){
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(s[i] == d){
                cnt++;
            }
        }
        if(cnt > mx){
            mx = cnt;
        }
    }
    for(char a = '0'; a <= '9'; ++a){
        for(char b = '0'; b <= '9'; ++b){
            if(a == b){
                continue;
            }

            int len = 0;
            char cur = a;
            for(int i=0; i<n; ++i){
                if(s[i] == cur){
                    len++;
                    if(cur == a){
                        cur = b;
                    }else{
                        cur = a;
                    }
                }
            }
            if(len % 2 != 0){
                len--;
            }
            if(len > mx){
                mx = len;
            }
        }
    }
    cout << n - mx << endl;
    return 0;
}