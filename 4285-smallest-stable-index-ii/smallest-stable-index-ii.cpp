class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        temp[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            temp[i] = min(nums[i], temp[i + 1]);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            if (mx - temp[i] <= k)
                return i;
        }
        return -1;
    }
};