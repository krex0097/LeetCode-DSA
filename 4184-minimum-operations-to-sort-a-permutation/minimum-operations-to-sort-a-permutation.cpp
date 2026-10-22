class Solution {
public:
    int f(vector<int>& nums, int idx) {
        int n = nums.size();
        if (nums[(idx + 1) % n] <= 1)
            return idx;
        return min(idx + 2, n - idx);
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (abs(nums[i] - nums[(i + 1) % n]) > 1)
                cnt++;
        if (cnt > 1)
            return -1;

        int idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int ans = f(nums, idx);
        reverse(nums.begin(), nums.end());
        idx = min_element(nums.begin(), nums.end()) - nums.begin();
        ans = min(ans, f(nums, idx) + 1);
        return ans;
    }
};
