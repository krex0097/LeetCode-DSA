class Solution {
public:
    int f(int n) {
        if (n < 100)
            return 0;
        int k = 0, cpy = n, cnt = 0;
        while (cpy)
            k++, cpy /= 10;
        int next = n % 10;
        n /= 10;
        int curr = n % 10;
        n /= 10;
        while (n) {
            int prev = n % 10;
            n /= 10;
            if ((curr < prev && curr < next) || (curr > next && curr > prev))
                cnt++;
            next = curr, curr = prev;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for (int i = num1; i <= num2; i++)
            cnt += f(i);
        return cnt;
    }
};