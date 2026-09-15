class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1)
            return n;
        int end = -1, ans = 0;
        for (int i = 0; i < n; i++)
            for (int l : {i - 1, i}) {
                int r = i;
                while (l > end && r < n && s[l] == s[r]) {
                    if (r - l + 1 >= k) {
                        ans++, end = r;
                        break;
                    }

                    l--, r++;
                }
            }
        return ans;
    }
};