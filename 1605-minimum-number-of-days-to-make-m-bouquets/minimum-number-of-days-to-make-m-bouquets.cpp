class Solution {
public:
    bool f(vector<int>& bloomDay, int m, int k, int x) {
        int curr = 0, freq = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] > x)
                curr = 0;
            else
                curr++;
            if (curr == k)
                curr = 0, freq++;
        }
        return freq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1LL* m * k  > n)
            return -1;
        int ans = -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end()),
            r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (f(bloomDay, m, k, mid))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
};