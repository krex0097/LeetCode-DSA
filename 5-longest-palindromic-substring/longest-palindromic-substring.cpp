class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int length = 1, idx = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2; j++) {
                int l = i, r = i;
                if (j == 0)
                    l = i - 1;
                while (l >= 0 && r < n && s[l] == s[r])
                    l--, r++;
                int len = r - l - 1;
                if (length < len)
                    idx = l + 1, length = len;
            }
        return s.substr(idx, length);
    }
};