/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long N = 1e9 + 7;
#define nap ""

using ll = long long;
const ll INF = 1e15;

struct Edge {
    int to;
    ll cap;
    int rev;
};

vector<vector<Edge>> g;
vector<int> lvl;
vector<size_t> itr;
int V;
int P, Q, R, D;
vector<vector<vector<int>>> v;

void ae(int u, int v_node, ll cap) {
    g[u].push_back({v_node, cap, (int)g[v_node].size()});
    g[v_node].push_back({u, 0, (int)g[u].size() - 1});
}

bool bfs(int s, int t) {
    lvl.assign(V, -1);
    queue<int> q;
    lvl[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto& e : g[u]) {
            if (e.cap > 0 && lvl[e.to] < 0) {
                lvl[e.to] = lvl[u] + 1;
                q.push(e.to);
            }
        }
    }
    return lvl[t] != -1;
}

ll dfs(int u, int t, ll f) {
    if (u == t) return f;
    for (size_t& i = itr[u]; i < g[u].size(); ++i) {
        Edge& e = g[u][i];
        if (e.cap > 0 && lvl[u] < lvl[e.to]) {
            ll d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(int s, int t) {
    ll flow = 0;
    while (bfs(s, t)) {
        itr.assign(V, 0);
        ll f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
    return flow;
}

int idx(int x, int y, int z) {
    return 1 + (x - 1) * Q * (R - 1) + (y - 1) * (R - 1) + (z - 1);
}

void hoathang() {
    cin >> P >> Q >> R >> D;
    v.assign(P + 1, vector<vector<int>>(Q + 1, vector<int>(R + 1)));
    for (int z = 1; z <= R; ++z) {
        for (int x = 1; x <= P; ++x) {
            for (int y = 1; y <= Q; ++y) {
                cin >> v[x][y][z];
            }
        }
    }

    if (R == 1) {
        ll total = 0;
        for (int x = 1; x <= P; ++x) {
            for (int y = 1; y <= Q; ++y) {
                total += v[x][y][1];
            }
        }
        cout << total << endl;
        return;
    }

    V = 2 + P * Q * (R - 1);
    g.assign(V, vector<Edge>());
    int S = 0, T = V - 1;

    for (int x = 1; x <= P; ++x) {
        for (int y = 1; y <= Q; ++y) {
            ae(S, idx(x, y, 1), v[x][y][1]);
            for (int z = 1; z < R - 1; ++z) {
                ae(idx(x, y, z), idx(x, y, z + 1), v[x][y][z + 1]);
            }
            ae(idx(x, y, R - 1), T, v[x][y][R]);
        }
    }

    int dx[] = {0, 1};
    int dy[] = {1, 0};

    for (int x = 1; x <= P; ++x) {
        for (int y = 1; y <= Q; ++y) {
            for (int i = 0; i < 2; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx > P || ny > Q) continue;
                for (int k = D + 2; k <= R; ++k) {
                    int h1 = k - 1;
                    int h2 = k - D - 1;
                    int n1_from = idx(x, y, h1);
                    int n2_to = idx(nx, ny, h2);
                    ae(n1_from, n2_to, INF);
                    int n2_from = idx(nx, ny, h1);
                    int n1_to = idx(x, y, h2);
                    ae(n2_from, n1_to, INF);
                }
            }
        }
    }
    cout << max_flow(S, T) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap ".inp", "r")) {
        freopen(nap ".inp", "r", stdin);
        freopen(nap ".out", "w", stdout);
    }
    int t;
    t = 1;
    // cin >> t;
    while (t--) {
        hoathang();
    }
    return 0;
}