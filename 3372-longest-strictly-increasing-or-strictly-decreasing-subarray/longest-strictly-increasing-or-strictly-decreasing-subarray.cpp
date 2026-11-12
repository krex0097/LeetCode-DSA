class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        if (n == 2)
            return (nums[1] == nums[0] ? 1 : 2);
        int cnt = 1, ans = 1;
        int asc = -1;
        if (nums[1] > nums[0])
            asc = 1, cnt = 2;
        else if (nums[1] < nums[0])
            asc = 0, cnt = 2;
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                ans = max(ans, cnt);
                asc = -1, cnt = 1;
                continue;
            }
            if ((asc == 1 && nums[i] > nums[i - 1]) ||
                (asc == 0 && nums[i] < nums[i - 1]))
                cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 2;
                asc=(nums[i] > nums[i - 1]?1:0);

            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};