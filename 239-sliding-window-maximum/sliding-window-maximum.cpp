class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> st(nums.begin(), nums.begin() + k);
        vector<int> ans;
        int i = 0, j = k - 1;
        while (j < n) {
            ans.push_back(*(st.rbegin()));
            auto it = st.find(nums[i]);
            st.erase(it);
            i++;
            j++;
            if (j < n)
                st.insert(nums[j]);
        }
        return ans;
    }
};