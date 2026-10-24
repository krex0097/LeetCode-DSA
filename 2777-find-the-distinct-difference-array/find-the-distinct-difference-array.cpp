class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++)
            st.insert(nums[i]), diff[i] = st.size();

        st.clear();
        for (int i = n - 1; i >= 0; i--)
            diff[i] -= st.size(), st.insert(nums[i]);

        return diff;
    }
};