class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x, i = 0, j = 0,
            ans = INT_MAX, sum = 0;
        while (j < n) {
            sum += nums[j];
            while (i <= j && sum > target) {
                sum -= nums[i];
                i++;
            }
            if (target == sum)
                ans = min(ans, i + n - j - 1);
            j++;
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};