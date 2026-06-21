/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "hoathang"

const int MAX = 1000005;
int N;
vector<pair<int,int>> pts;
vector<int> idx_by_row[MAX];
vector<int> idx_by_col[MAX];
bool lamp[MAX];
int min_y_row[MAX], max_y_row[MAX];
int min_x_col[MAX], max_x_col[MAX];

void hoathang(){
    cin >> N;
    pts.resize(N);
    for(int i=0; i<N; i++){
        cin >> pts[i].first >> pts[i].second;
        int x = pts[i].first, y = pts[i].second;
        idx_by_row[x].push_back(i);
        idx_by_col[y].push_back(i);
    }

    for(int x=0; x<MAX; x++){
        if(!idx_by_row[x].empty()){
            sort(idx_by_row[x].begin(), idx_by_row[x].end(), [&](int i, int j){
                return pts[i].second < pts[j].second;
            });
        }
    }
    for(int y=0; y<MAX; y++){
        if(!idx_by_col[y].empty()){
            sort(idx_by_col[y].begin(), idx_by_col[y].end(), [&](int i, int j){
                return pts[i].first < pts[j].first;
            });
        }
    }

    fill(lamp, lamp+N, false);
    for(int x=0; x<MAX; x++){
        if(idx_by_row[x].size() >= 1){
            int id_min = idx_by_row[x][0];
            lamp[id_min] = true;
            int id_max = idx_by_row[x].back();
            lamp[id_max] = true;
        }
    }
    for(int y=0; y<MAX; y++){
        if(idx_by_col[y].empty()) continue;
        vector<int> lamp_ids;
        for(int id : idx_by_col[y]){
            if(lamp[id]) lamp_ids.push_back(id);
        }
        if(lamp_ids.size() > 2){
            int id_min_x = lamp_ids[0];
            int id_max_x = lamp_ids.back();
            for(int id : lamp_ids){
                if(id != id_min_x && id != id_max_x){
                    lamp[id] = false;
                }
            }
        }
    }
    for(int x=0; x<MAX; x++){
        min_y_row[x] = INT_MAX;
        max_y_row[x] = -1;
    }
    for(int y=0; y<MAX; y++){
        min_x_col[y] = INT_MAX;
        max_x_col[y] = -1;
    }
    for(int i=0; i<N; i++){
        if(lamp[i]){
            int x = pts[i].first, y = pts[i].second;
            if(y < min_y_row[x]) min_y_row[x] = y;
            if(y > max_y_row[x]) max_y_row[x] = y;
            if(x < min_x_col[y]) min_x_col[y] = x;
            if(x > max_x_col[y]) max_x_col[y] = x;
        }
    }
    for(int i=0; i<N; i++){
        if(lamp[i]) continue;
        int x = pts[i].first, y = pts[i].second;
        bool ok = false;
        if(min_y_row[x] != INT_MAX && max_y_row[x] != -1){
            if(min_y_row[x] < y && y < max_y_row[x]) ok = true;
        }
        if(!ok && min_x_col[y] != INT_MAX && max_x_col[y] != -1){
            if(min_x_col[y] < x && x < max_x_col[y]) ok = true;
        }
        if(!ok){
            lamp[i] = true;
            if(y < min_y_row[x]) min_y_row[x] = y;
            if(y > max_y_row[x]) max_y_row[x] = y;
            if(x < min_x_col[y]) min_x_col[y] = x;
            if(x > max_x_col[y]) max_x_col[y] = x;
        }
    }

    for(int i=0; i<N; i++){
        cout << (lamp[i] ? '1' : '0');
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
