class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> digSum;
        for (int i = 0; i < n; i++) {
            int val = nums[i], sum = 0;
            while (val > 0)
                sum += val % 10, val /= 10;
            digSum.push_back({sum, nums[i], i});
        }
        sort(digSum.begin(), digSum.end());
        vector<bool> vis(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || i == digSum[i][2])
                continue;
            int len = 0, j = i;
            while (!vis[j])
                vis[j] = true, j = digSum[j][2], len++;
            swaps += len - 1;
        }
        return swaps;
    }
};