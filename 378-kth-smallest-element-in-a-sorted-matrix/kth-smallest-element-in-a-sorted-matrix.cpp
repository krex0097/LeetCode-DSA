class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        for (int i = 0; i < n; i++)
            pq.push({matrix[i][0], i, 0});
        for (int i = 1; i < k; i++) {
            int idx = pq.top()[2]+1, r = pq.top()[1];
            pq.pop();
            if (idx < n)
                pq.push({matrix[r][idx], r, idx});
        }
        return pq.top()[0];
    }
};