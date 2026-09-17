class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        vector<int> last(n, INT_MAX);
        int minLen = INT_MAX, minPair = INT_MAX, sum = 0;
        while (j < n) {
            sum += arr[j];
            last[j] = minLen;
            while (i <= j && sum > target)
                sum -= arr[i], i++;
            if (sum == target) {
                int len = j - i + 1;
                minLen = min(minLen, len);
                last[j] = minLen;
                if (i > 0 && last[i - 1] != INT_MAX)
                    minPair = min(minPair, last[i - 1] + len);
            }
            j++;
        }
        return (minPair != INT_MAX ? minPair : -1);
    }
};