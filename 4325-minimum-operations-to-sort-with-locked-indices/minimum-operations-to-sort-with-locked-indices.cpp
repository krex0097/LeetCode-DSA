class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                int l, r;
                if (nums[i] < i + 1) {
                    l = nums[i] - 1;
                    r = i;
                } else {
                    l = i;
                    r = nums[i] - 1;
                }

                for (int j = l; j <= r; j++) {
                    if (locked[j]) {
                        cnt++;
                        locked[j] = 0;
                    }
                    if (cnt > k)
                        return -1;
                }
            }
        }

        int ans = cnt;
        int total_swaps = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    total_swaps++;
                }
            }
        }
        return ans + total_swaps;
    }
};
