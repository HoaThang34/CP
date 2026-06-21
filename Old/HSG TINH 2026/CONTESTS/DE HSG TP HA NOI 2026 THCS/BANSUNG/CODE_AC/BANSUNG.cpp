#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// Function to check if power X is sufficient
// N targets, Max K shots.
// Array A is modified during simulation, so pass by value or copy.
bool check(int N, int K, vector<long long> A, long long X) {
    if (X == 0) {
        // Only if all A[i] <= 0 initially
        for(long long v : A) if(v > 0) return false;
        return true;
    }

    int shots = 0;
    // We can simulate slightly optimized.
    // We shoot the FIRST alive target.
    // Optimization: Keep track of first alive index.
    
    int first_alive = 0;
    while (shots < K) {
        // Find first alive
        while(first_alive < N && A[first_alive] <= 0) {
            first_alive++;
        }
        
        if (first_alive >= N) return true; // All destroyed
        
        // Shoot at 'first_alive'
        shots++;
        int i = first_alive; // Target hit
        
        // Apply damage to i and subsequent j > i
        // Damage: max(0, X - (j-i)^2)
        // Only need to go until X - (j-i)^2 <= 0
        // i.e., (j-i)^2 >= X => j-i >= sqrt(X) => j >= i + sqrt(X)
        
        // Range to affect: [i, i + sqrt(X) )
        long long range_lim = sqrt(X);
        if (range_lim * range_lim < X) range_lim++; 
        // Be careful with sqrt precision.
        // Or just iterate until diff^2 >= X.
        
        for (int j = i; j < N; ++j) {
            long long dist = (long long)(j - i);
            long long reduction = X - dist * dist;
            if (reduction <= 0) break; // No more effect
            A[j] -= reduction;
        }
    }
    
    // Check if all destroyed
    while(first_alive < N && A[first_alive] <= 0) first_alive++;
    return first_alive >= N;
}

int main() {
    fast_io();
    if (fopen("BANSUNG.INP", "r")) {
        freopen("BANSUNG.INP", "r", stdin);
        freopen("BANSUNG.OUT", "w", stdout);
    }

    int N, K;
    if (cin >> N >> K) {
        vector<long long> A(N);
        long long max_val = 0;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            max_val = max(max_val, A[i]);
        }

        // Binary search for X
        // Range: [1, Max possible needed]
        // If K=1 and A[i] is huge, X needs to be huge?
        // Wait, max durability is small? "Max value up to 10" in example but text says "A_i <= 10^9"?
        // Text said "20% A_i < 10". So A_i can be large.
        // If A_i = 10^9, we need X >= 10^9 to kill it in 1 shot.
        // Upper bound: Max(A) + N^2 ? No.
        // If we shoot directly, we do X damage.
        // To kill something with HP H in 1 shot, need X >= H.
        // In K shots, maybe less.
        // Safe upper bound: Max(A) + something? Or 2e14?
        // Let's use 2e14 (as constraints mentioned S <= 10^14 in previous problem, maybe similar here).
        // Actually A_i sum?
        // Let's stick to 1e15.
        
        long long low = 1, high = 200000000000000LL; // 2e14
        long long ans = high;

        // Optimization: if K is large enough to kill one by one?
        // If K >= N, then X = Max(A) is sufficient (kill each with 1 shot).
        // If reduction logic helps, X could be smaller.
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(N, K, A, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
