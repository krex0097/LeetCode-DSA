class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int idx = min_element(nums.begin(), nums.end()) - nums.begin();

        bool asc = true, dsc = true;

        for (int i = 0; i < n; i++) {
            if (nums[(idx + i) % n] != i)
                asc = false;

            if (nums[(idx - i + n) % n] != i)
                dsc = false;
        }

        if (asc)
            return min(idx, n - idx + 2);

        if (dsc)
            return min(idx + 2, n - idx);

        return -1;
    }
};