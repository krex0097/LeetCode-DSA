class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, string& s, string& t) {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = f(i - 1, j, s, t) + f(i - 1, j - 1, s, t);
        else
            return dp[i][j] = f(i - 1, j, s, t);
    }
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        dp.assign(m, vector<int>(n, -1));
        return f(m - 1, n - 1, s, t);
    }
};