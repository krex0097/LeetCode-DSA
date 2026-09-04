class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int r = 0; r < m; r++) {
            int c = lower_bound(matrix[r].begin(), matrix[r].end(), target) -
                    matrix[r].begin();
            if (c < n && matrix[r][c] == target)
                return true;
        }
        return false;
    }
};