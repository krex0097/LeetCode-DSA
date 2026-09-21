class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        vector<long long> prev(k, 0), curr(k, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                long long newRem = (1LL * j * nums[i]) % k;
                curr[newRem] += prev[j];
            }
            curr[nums[i] % k]++;
            for (int j = 0; j < k; j++)
                ans[j] += curr[j];
            prev = curr;
            curr.assign(k, 0);
        }
        return ans;
    }
};