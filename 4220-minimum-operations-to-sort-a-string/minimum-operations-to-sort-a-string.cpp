class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        char mn = *min_element(s.begin(), s.end()),
             mx = *max_element(s.begin(), s.end());
        int cntMin = 0, cntMax = 0;
        for (auto& it : s)
            if (it == mn)
                cntMin++;
            else if (it == mx)
                cntMax++;
        bool sorted = true;
        for (int i = 0; i < n - 1; i++)
            if (s[i] > s[i + 1]) {
                sorted = false;
                break;
            }
        if (sorted)
            return 0;
        if(n==2)return -1;
        if(s[0]==mn || s[n-1]==mx)return 1;
        if(s[0]==mx && s[n-1]==mn)
            if(cntMax==1 && cntMin==1)return 3;
            else return 2;
        return 2;
    }
};