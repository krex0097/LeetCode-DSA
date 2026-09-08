class Solution {
public:
    using ll = long long;
    long long countCommas(long long n) {
        if (n < 1000)
            return 0;
        ll next = 999999LL, curr = 999, ans = 0LL;
        int commas = 1;
        while (true) {
            ans += (min(next, n) - curr) * commas;
            if (next > n)
                break;
            curr = next;
            next = (next + 1) * 1000 -1;
            commas++;
        }
        return ans;
    }
};