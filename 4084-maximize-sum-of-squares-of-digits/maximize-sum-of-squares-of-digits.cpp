class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string val = "";
        int cnt = 0, digSum = 0;
        while (cnt < num && digSum + 9 <= sum)
            val += '9', cnt++, digSum += 9;
        char diff =(sum - digSum)+'0';
        if (cnt < num && sum - digSum)
            val += diff, digSum = sum, cnt++;
        while (cnt < num)
            val += '0', cnt++;

        return (digSum == sum ? val : "");
    }
};