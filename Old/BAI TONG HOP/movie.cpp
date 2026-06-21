#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> st;
    SegTree() {}
    SegTree(const vector<int>& a) { build(a); }
    void build(const vector<int>& a) {
        int m = (int)a.size();
        n = 1; while (n < m) n <<= 1;
        st.assign(2*n, 0);
        for (int i = 0; i < m; ++i) st[n+i] = a[i];
        for (int i = n-1; i >= 1; --i) st[i] = max(st[i<<1], st[i<<1|1]);
    }
    int query(int l, int r) const {
        if (l > r) return 0;
        l += n; r += n;
        int res = 0;
        while (l <= r) {
            if (l & 1) res = max(res, st[l++]);
            if (!(r & 1)) res = max(res, st[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n+1), val(n+1);
    for (int i = 1; i <= n; ++i) {
        int Ai, Bi;
        cin >> Ai >> Bi;
        a[i] = Ai;
        val[i] = (Bi ? 1 : -1);
    }
    vector<int> posByCity(n+1);
    for (int i = 1; i <= n; ++i) posByCity[a[i]] = i;

    vector<int> S(n+1, 0);
    for (int i = 1; i <= n; ++i) S[i] = S[i-1] + val[i];

    vector<int> allS = S;
    sort(allS.begin(), allS.end());
    allS.erase(unique(allS.begin(), allS.end()), allS.end());
    auto getIdx = [&](int s)->int {
        return (int)(lower_bound(allS.begin(), allS.end(), s) - allS.begin());
    };
    int M = (int)allS.size();

    vector<int> sIdx(n+1);
    for (int i = 0; i <= n; ++i) sIdx[i] = getIdx(S[i]);

    vector<int> lastOccComp(M, 0);
    for (int i = 0; i <= n; ++i) lastOccComp[sIdx[i]] = i;

    SegTree seg(lastOccComp);

    vector<int> nextSame(n+1, -1), lastSame(n+1, -1);
    {
        vector<int> lastSeen(M, -1);
        for (int i = n; i >= 0; --i) {
            nextSame[i] = lastSeen[sIdx[i]];
            lastSeen[sIdx[i]] = i;
        }
        for (int i = 0; i <= n; ++i) lastSame[i] = lastOccComp[sIdx[i]];
    }

    auto feasibleD0 = [&](int needM)->bool {
        int p = 0, minCnt = 0;
        bool ok = true;
        while (p < n) {
            int j = lastSame[p];
            if (j <= p) { ok = false; break; }
            p = j; ++minCnt;
        }
        if (!ok) return false;
        p = 0;
        int maxCnt = 0;
        ok = true;
        while (p < n) {
            int j = nextSame[p];
            if (j == -1) { ok = false; break; }
            p = j; ++maxCnt;
        }
        if (!ok) return false;
        return (minCnt <= needM && needM <= maxCnt);
    };

    auto minSegmentsGivenD = [&](int D)->pair<bool,int> {
        int p = 0, cnt = 0;
        while (p < n) {
            int L = (int)(lower_bound(allS.begin(), allS.end(), S[p]-D) - allS.begin());
            int R = (int)(upper_bound(allS.begin(), allS.end(), S[p]+D) - allS.begin()) - 1;
            if (L > R) return {false, 0};
            int j = seg.query(L, R);
            if (j <= p) return {false, 0};
            p = j; ++cnt;
        }
        return {true, cnt};
    };

    int lo = 0, hi = n, bestD = n;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        bool ok;
        if (mid == 0) ok = feasibleD0(m);
        else {
            auto res = minSegmentsGivenD(mid);
            ok = (res.first && res.second <= m);
        }
        if (ok) { bestD = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    int D = bestD;

    vector<int> answer;
    answer.reserve(m);

    if (D == 0) {
        const int INF = n + 5;
        vector<int> minSeg0(n+1, INF), maxSeg0(n+1, -INF);
        minSeg0[n] = 0; maxSeg0[n] = 0;
        for (int p = n-1; p >= 0; --p) {
            int jLast = lastSame[p];
            if (jLast > p) {
                if (minSeg0[jLast] < INF) minSeg0[p] = 1 + minSeg0[jLast];
            }
            int jNext = nextSame[p];
            if (jNext != -1) {
                if (maxSeg0[jNext] > -INF) maxSeg0[p] = 1 + maxSeg0[jNext];
            }
        }
        vector<vector<int>> buckets(M);
        for (int j = 1; j <= n; ++j) buckets[sIdx[j]].push_back(j);
        for (int c = 0; c < M; ++c) {
            auto &v = buckets[c];
            sort(v.begin(), v.end(), [&](int p, int q){
                return a[p] < a[q];
            });
        }
        vector<int> ptr(M, 0);

        int p = 0;
        for (int step = 1; step <= m-1; ++step) {
            int needed = m - step;
            int c = sIdx[p];
            int bestCity = INT_MAX, bestPos = -1;
            auto &vec = buckets[c];
            int &k = ptr[c];
            while (k < (int)vec.size()) {
                int j = vec[k];
                if (j <= p) { ++k; continue; }
                int rem = n - j;
                int minNeed = minSeg0[j];
                int maxNeed = maxSeg0[j];
                if (minNeed == n+5) { ++k; continue; }
                if (rem < needed) { ++k; continue; }
                if (!(minNeed <= needed && needed <= maxNeed)) { ++k; continue; }
                bestCity = a[j]; bestPos = j;
                break;
            }
            if (bestPos == -1) {
                bestPos = n;
                bestCity = a[n];
            }
            answer.push_back(bestCity);
            p = bestPos;
        }
        answer.push_back(a[n]);
    } else {
        vector<int> nextPos(n+1, -1);
        nextPos[n] = n;
        for (int p = 0; p < n; ++p) {
            int L = (int)(lower_bound(allS.begin(), allS.end(), S[p]-D) - allS.begin());
            int R = (int)(upper_bound(allS.begin(), allS.end(), S[p]+D) - allS.begin()) - 1;
            if (L > R) { nextPos[p] = -1; continue; }
            int j = seg.query(L, R);
            nextPos[p] = (j > p ? j : -1);
        }
        const int LOG = 20;
        vector<array<int, 20>> up(n+1);
        for (int i = 0; i <= n; ++i) {
            up[i].fill(-1);
            up[i][0] = nextPos[i];
        }
        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i <= n; ++i) {
                int u = up[i][k-1];
                up[i][k] = (u == -1 ? -1 : up[u][k-1]);
            }
        }
        auto minSegFrom = [&](int start)->int {
            if (start == n) return 0;
            if (nextPos[start] == -1) return n+5;
            int node = start, cnt = 0;
            for (int k = LOG-1; k >= 0; --k) {
                int v = up[node][k];
                if (v != -1 && v < n) {
                    node = v;
                    cnt += (1<<k);
                }
            }
            if (up[node][0] == -1) return n+5;
            return cnt + 1;
        };

        vector<int> minSegAll(n+1, n+5);
        for (int j = 0; j <= n; ++j) minSegAll[j] = minSegFrom(j);

        vector<vector<int>> buckets(M);
        for (int j = 1; j <= n; ++j) buckets[sIdx[j]].push_back(j);
        for (int c = 0; c < M; ++c) {
            auto &v = buckets[c];
            sort(v.begin(), v.end(), [&](int p, int q){
                return a[p] < a[q];
            });
        }
        vector<int> ptr(M, 0);

        int p = 0;
        for (int step = 1; step <= m-1; ++step) {
            int needed = m - step;
            int Ls = (int)(lower_bound(allS.begin(), allS.end(), S[p]-D) - allS.begin());
            int Rs = (int)(upper_bound(allS.begin(), allS.end(), S[p]+D) - allS.begin()) - 1;
            int bestCity = INT_MAX, bestPos = -1;
            for (int c = Ls; c <= Rs; ++c) {
                auto &vec = buckets[c];
                int &k = ptr[c];
                while (k < (int)vec.size()) {
                    int j = vec[k];
                    if (j <= p) { ++k; continue; }
                    if (minSegAll[j] > needed) { ++k; continue; }
                    if ((n - j) < needed) { ++k; continue; }
                    int city = a[j];
                    if (city < bestCity) {
                        bestCity = city;
                        bestPos = j;
                    }
                    break;
                }
            }
            if (bestPos == -1) {
                bestPos = nextPos[p];
                if (bestPos == -1) bestPos = n;
                bestCity = a[bestPos];
            }
            answer.push_back(bestCity);
            p = bestPos;
        }
        answer.push_back(a[n]);
    }

    for (int i = 0; i < m; ++i) {
        if (i) cout << ' ';
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}
