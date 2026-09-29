class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int, int>, int > mp;
        int n=nums.size();
        for (int i = 0; i < n - 1; i++)
            if (nums[i] != nums[i + 1]) {
                int l = nums[i], r = nums[i + 1];
                mp[{min(l, r), max(l, r)}]++;
            }
        int ele = 0, change = 0, freq = 0;
        for (auto it : mp)
            if (freq < it.second) {
                ele = it.first.first;
                change = it.first.second;
                freq = it.second;
            }
        int cnt = 0;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == ele)
                nums[i] = change;
            if(nums[i+1]==ele)nums[i+1]=change;
            if (nums[i] == nums[i + 1])
                cnt++;
        }
        return cnt;
    }
};