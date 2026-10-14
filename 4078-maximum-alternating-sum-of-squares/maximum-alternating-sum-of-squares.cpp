class Solution {
public:
    using ll = long long;
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = nums;
        for (auto& it : a)
            it = abs(it);
        sort(a.begin(), a.end(), greater<int>());
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ll toAdd = 1LL * a[i] * a[i];
            if (i < (n + 1) / 2)
                sum += toAdd;
            else
                sum -= toAdd;
        }
        return sum;
    }
};