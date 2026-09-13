class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<vector<int>> freq(2 * n, vector<int>(2 * n, 0));
        int mx = 0;
        for (int i2 = 0; i2 < n; i2++)
            for (int j2 = 0; j2 < n; j2++)
                for (int i1 = 0; i1 < n; i1++)
                    for (int j1 = 0; j1 < n; j1++)
                        if (img1[i1][j1] && img2[i2][j2]) {
                            freq[i1 - i2 + n][j1 - j2 + n]++;
                            mx = max(mx, freq[i1 - i2 + n][j1 - j2 + n]);
                        }
        return mx;
    }
};