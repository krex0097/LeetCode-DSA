class Solution {
public:
    bool check(vector<int>& freq, int x) {
        for (int i = 1; i <= 500 - x; i++)
            if (freq[i] && freq[i + x])
                return false;
        for (int i = 1; i < x; i++)
            if ((i == x - i && freq[i] > 1) ||
                (i != x - i && freq[i] && freq[x - i]))
                return false;

        return true;
    }
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, l = 0, ans = 0;
        vector<int> freq(501);
        while (i < n) {
            if (i < n && check(freq, nums[i])) {
                freq[nums[i]]++;
                i++;
                ans = max(i - l, ans);
            } else {
                freq[nums[l]]--;
                l++;
            }
        }
        return ans;
    }
};