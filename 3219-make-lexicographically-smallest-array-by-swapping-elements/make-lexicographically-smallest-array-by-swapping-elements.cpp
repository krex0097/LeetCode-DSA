class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++)
            p.push_back({nums[i], i});
        sort(p.begin(), p.end());
        vector<vector<pair<int, int>>> grps;
        grps.push_back({p[0]});
        for (int i = 1; i < n; i++)
            if (abs(p[i].first - p[i - 1].first) <= limit)
                grps.back().push_back(p[i]);
            else
                grps.push_back({p[i]});
        vector<int> ans(n);
        for (int i = 0; i < grps.size(); i++) {
            int gs = grps[i].size();
            vector<int> sortedIdx;
            for (int j = 0; j < gs; j++)
                sortedIdx.push_back(grps[i][j].second);
            sort(sortedIdx.begin(), sortedIdx.end());
            for (int j = 0; j < gs; j++)
                ans[sortedIdx[j]] = grps[i][j].first;
        }
        return ans;
    }
};