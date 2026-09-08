class Solution {
public:
    const int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        vector<long long> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';
            dp[i] = (2 * dp[i - 1] + 1) % MOD;
            if (last[c] != -1)
                dp[i] = (2 * dp[i - 1] - dp[last[c] - 1] + MOD) % MOD;
            last[c]=i;
        }

        return dp[n]%MOD;
    }
};