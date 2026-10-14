class Solution {
public:
    using ll = long long;
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (auto& it : nums)
            it = abs(it);
        sort(nums.begin(), nums.end(), greater<int>());
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ll toAdd = 1LL * nums[i] * nums[i];
            if (i < (n + 1) / 2)
                sum += toAdd;
            else
                sum -= toAdd;
        }
        return sum;
    }
};