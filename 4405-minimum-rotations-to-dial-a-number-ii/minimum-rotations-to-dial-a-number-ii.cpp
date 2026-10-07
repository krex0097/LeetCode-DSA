class Solution {
public:
    int minRotations(int n, string s) {
        int curr = 0, total = 0;
        for (int i = 0; i < n; i++) {
            int val = s[i] - '0';
            total += min({abs(curr - val), 10 - abs(curr - val)});
            curr = val;
        }
        int prev = 0, last = s[n - 1] - '0', ans = total;
        for (int i = 0; i < n - 1; i++) {
            int val = s[i] - '0';
            int currDiff = min({abs(prev - val), 10 - abs(prev - val)}),
                lastDiff = min({abs(prev - last), 10 - abs(prev - last)});
            ans = min(ans, total - currDiff + lastDiff);
            prev = val;
        }
        return ans;
    }
};