class Solution {
public:
    using ll = long long;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        vector<ll> count(1e5 + 1, 0);
        for (int i = 0; i < n; i++)
            count[abs(nums1[i] - nums2[i])]++;
        ll ops = k1 + k2;
        for (int i = 1e5; i > 0 && ops > 0; i--) {
            ll reduce = min(count[i], ops);
            count[i] -= reduce;
            count[i - 1] += reduce;
            ops -= reduce;
        }
        ll ans = 0;
        for (int i = 1; i < count.size(); i++) {
            ll sum = i * 1LL * i;
            sum *= count[i];
            ans += sum;
        }
        return ans;
    }
};