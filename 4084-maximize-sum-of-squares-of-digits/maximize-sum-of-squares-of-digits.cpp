class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum)
            return "";
        int nines = sum / 9, rem = sum % 9;
          string ans(nines, '9');

        if (rem) ans += char(rem + '0');

        ans += string(num - ans.size(), '0');
        return ans;
    }
};