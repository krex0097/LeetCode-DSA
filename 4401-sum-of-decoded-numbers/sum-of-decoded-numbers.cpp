class Solution {
public:
    using ll = long long;
    const int MOD = 1000000007;
    ll binpow(ll x, ll y) {
        ll ans = 1;
        x %= MOD, y %= MOD;
        while (y) {
            if (y % 2 == 1)
                ans = (ans * x) % MOD;
            x = (x * x) % MOD;
            y /= 2;
        }
        return ans;
    }
    ll f(ll num) {
        ll w = num % 10, d = num / 10;
        ll x = d, y = 0, dig = 0;
        while (x) {
            x /= 10;
            dig++;
        }
        x = d;
        ll rem = dig - w, cnt = 0;
        while (cnt < rem) {
            cnt++;
            x /= 10;
        }
        ll sub = x;
        while (rem--)
            sub *= 10;

        y = d - sub;
        return binpow(x, y);
    }
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans = (ans + f(nums[i])) % MOD;

        return ans;
    }
};