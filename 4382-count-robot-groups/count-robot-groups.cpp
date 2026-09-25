class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        if (n == 1)
            return 1;
        vector<int> p = {speed[0]};
        int last = position[0];
        for (int i = 1; i < n; i++) {
            if (position[i] - last <= distance)
                p.pop_back();
            p.push_back(speed[i]);
            last = position[i];
        }

        int sz = p.size();
        last = p[sz - 1];
        int grps = 1;
        for (int i = sz - 2; i >= 0; i--)
            if (p[i] <= last) {
                last = p[i];
                grps++;
            }

        return grps;
    }
};