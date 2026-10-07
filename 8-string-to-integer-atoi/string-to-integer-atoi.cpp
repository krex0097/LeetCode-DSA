class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        while (i < n && s[i] == ' ')
            i++;
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }
        long long ans = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int val = s[i] - '0';
            if (ans > (INT_MAX - val) / 10)
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            ans = ans * 10 + val;
            i++;
        }

        return sign*ans;
    }
};