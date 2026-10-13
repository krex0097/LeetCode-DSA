class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> next(n, -1);
        int idx = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (idx != -1)
                next[i] = idx;
            if (nums[i] < 0)
                idx = i;
            else if (nums[i] == 0)
                idx = -1;
        }
        int j = 0, i = 0;
        int prod = 1;
        while (j < n) {
            prod *= nums[j];
            mx = max(mx, prod);
            if (!prod){
                prod = 1;
                i=j+1;
            }
            else if (prod < 0 && next[j] == -1){
                while (i <= j && prod < 0) {
                    prod /= nums[i];
                    i++;
                }
                if(i<=j)
                mx=max(mx,prod);
            }
            j++;
        }
        return mx;
    }
};