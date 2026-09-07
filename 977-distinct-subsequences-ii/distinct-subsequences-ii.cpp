class Solution {
public:
    using ll = long long;
    const ll MOD= 1000000007;
    vector<int> dp, prev, last;
    ll f(int i) {
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        ll before = f(i - 1);
        ll add = (before + 1) % MOD;
        int p = prev[i];
        if (p != -1) {
            ll dup = f(p - 1);
            add = (before - dup + MOD) % MOD;
        }
        return dp[i] = (before + add) % MOD;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        dp.assign(n, -1), prev.assign(n, -1), last.assign(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            prev[i] = last[c];
            last[c] = i;
        }
        return f(n - 1);
    }
};