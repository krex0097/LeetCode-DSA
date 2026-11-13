class Solution {
public:
    int count(vector<vector<int>>& matrix, int mid) {
        int cnt = 0, n = matrix.size();
        int c = n - 1;
        for (int r = 0; r < n; r++) {
            while (c >= 0 && matrix[r][c] > mid)
                c--;
            cnt += c + 1;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), l = matrix[0][0], r = matrix[n - 1][n - 1],
            ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (count(matrix, mid) >= k)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
};