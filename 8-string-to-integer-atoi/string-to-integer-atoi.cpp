class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        while (i < n && s[i] == ' ')
            i++;
        int neg = 0;
        if (i < n &&
            (s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9'))) {
            if (s[i] == '-')
                neg = 1;
        } else
            return 0;
        if (s[i] == '+' || s[i] == '-')
            i++;
        while (i < n && s[i] == '0')
            i++;
        if (i == n || s[i] > '9' || s[i] < '0')
            return 0;
        vector<int> num;
        while (i < n && s[i] <= '9' && s[i] >= '0') {
            num.push_back(s[i] - '0');
            i++;
        }
        long long ans = 0;
        long long mul = 1;
        int sz = num.size();
        if (sz > 10)
            if (neg)
                return INT_MIN;
            else
                return INT_MAX;
        for (int j = sz - 1; j >= 0; j--) {
            ans += num[j] * mul;
            if (neg) {
                if (ans * -1 <= INT_MIN)
                    return INT_MIN;
            } else if (ans >= INT_MAX)
                return INT_MAX;
            mul *= 10;            
        }
        if (neg)
            ans *= -1;
        return ans;
    }
};