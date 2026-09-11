class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> freq(10, 0);
        int cnt = 0;
        for (auto it : digits)
            freq[it]++;
        for (int i = 100; i < 999; i += 2) {
            int val = i;
            vector<int> f(10, 0);
            bool possible = true;
            while (val) {
                int rem = val % 10;
                f[rem]++;
                if (f[rem] > freq[rem]) {
                    possible = false;
                    break;
                }
                val /= 10;
            }
            if (possible)
                cnt++;
        }
        return cnt;
    }
};