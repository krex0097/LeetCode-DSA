class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++)
            p.push_back({nums[i], i});
        sort(p.begin(), p.end());
        vector<int> ans(n);
        int i = 0;
        while (i < n) {
            int j = i + 1;
            vector<int> sortedIdx;
            while (j<n && abs(p[j].first - p[j - 1].first) <= limit)
                j++;
            for (int k = i; k < j; k++)
                sortedIdx.push_back(p[k].second);
            sort(sortedIdx.begin(), sortedIdx.end());
            for (int k = i; k < j; k++)
                ans[sortedIdx[k - i]] = p[k].first;
            i=j;
        }
        return ans;
    }
};