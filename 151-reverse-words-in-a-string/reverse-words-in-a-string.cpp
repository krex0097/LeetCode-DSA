class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;
        vector<string> words;
        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            int start = i;
            while (i < n && s[i] != ' ')
                i++;
            if (start < i)
                words.push_back(s.substr(start, i-start));
        }
        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            if (i > 0)
                ans += " ";
        }

        return ans;
    }
};