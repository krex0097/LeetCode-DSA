class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;
        string nw = " ";
        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            while (i < n && s[i] != ' ') {
                nw += s[i];
                i++;
            }
            if (nw.size() > 1) {
                ans.insert(ans.begin(), nw.begin(), nw.end());
                nw = " ";
            }
        }
        if (ans.size() > 0)
            ans = ans.substr(1, ans.size());
        ;
        return ans;
    }
};