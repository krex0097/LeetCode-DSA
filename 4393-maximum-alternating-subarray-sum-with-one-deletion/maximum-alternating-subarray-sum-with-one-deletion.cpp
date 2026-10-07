class Solution {
public:
    using ll = long long;
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        ll pe0 = INT_MIN, po0 = nums[0], pe1 = INT_MIN, po1 = INT_MIN, ce0, co0,
           ce1, co1;
        ll mx = nums[0];
        for (int i = 1; i < n; i++) {
            co0 = max(nums[i]*1LL, pe0 + nums[i]), ce0 = po0 - nums[i],
            co1 = max(nums[i] + pe1, po0), ce1 = max(-nums[i] + po1, pe0);
            mx = max({mx,co0, ce0, co1, ce1});
            pe0 = ce0, po0 = co0, pe1 = ce1, po1 = co1;
        }
        return mx;
    }
};