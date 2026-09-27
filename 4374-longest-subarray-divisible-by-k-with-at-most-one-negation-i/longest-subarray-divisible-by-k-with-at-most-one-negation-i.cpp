class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                st.insert(((2 * nums[j]) % k + k) % k);
                int rem = ((sum % k) + k) % k;
                if (sum % k == 0 || st.find(rem) != st.end())
                    len = max(len, j - i + 1);
            }
        }
        return len;
    }
};