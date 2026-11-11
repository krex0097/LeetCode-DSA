class Solution {
public:
    using ll = long long;

    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        if (need1 > need2) {
            swap(need1, need2);
            swap(cost1, cost2);
        }

        ll ans = 1LL * cost1 * need1 + 1LL * cost2 * need2;

        if (1LL * costBoth > 1LL * cost1 + cost2)
            return ans;

        ans = min({
            ans,
            1LL * need2 * costBoth,
            1LL * (need2 - need1) * cost2 + 1LL * need1 * costBoth
        });

        return ans;
    }
};