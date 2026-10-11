class Solution {
public:
    using ll = long long;
    bool f(vector<int>& diff, int mid, ll ops) {
        for (int i = diff.size() - 1; i >= 0 && diff[i] > mid; i--) {
            if (ops >= diff[i] - mid)
                ops -= diff[i] - mid;
            else
                return false;
        }
        return true;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++)
            diff[i] = abs(nums1[i] - nums2[i]);
        ll sum = accumulate(diff.begin(), diff.end(), 0LL), ops = k1 + k2;
        ;
        if (!sum || sum <= ops)
            return 0;

        sort(diff.begin(), diff.end());
        int l = 0, r = diff.back();
        int mx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (f(diff, mid, ops))
                mx = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        ll ans = 0;
        int d = diff.size(), freq = 0;
        for (int i = 0; i < n && diff[i] < mx; i++)
            ans += 1LL * diff[i] * diff[i];
        for (int i = d - 1; i >= 0 && diff[i] >= mx; i--) {
            if (diff[i] == mx)
                freq++;
            else {
                ops -= diff[i] - mx;
                freq++;
            }
        }
        ans += ops * (mx - 1) * (mx - 1);
        ans += (freq - ops) * mx * mx;

        return ans;
    }
};