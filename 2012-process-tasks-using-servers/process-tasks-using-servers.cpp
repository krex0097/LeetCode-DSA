class Solution {
public:
    using ll=long long;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int s = servers.size(), t = tasks.size();
        priority_queue<pair<long, int>, vector<pair<long, int>>,
                       greater<pair<long, int>>>
            avl, busy;
        for (int i = 0; i < s; i++)
            avl.push({servers[i], i});
        vector<int> ans(t);
         long long curr = 0;
        for (int i = 0; i < t; i++) {
            curr= max(curr, 1LL*i);
            while (!busy.empty() && busy.top().first <= curr) {
                auto [time, idx] = busy.top();
                avl.push({servers[idx], idx});
                busy.pop();
            }           
            if (avl.empty()) {
                curr = busy.top().first;
                while (!busy.empty() && busy.top().first == curr) {
                    auto [time, idx] = busy.top();
                    busy.pop();
                    avl.push({servers[idx], idx});
                }
            }
            auto [x, y] = avl.top();
            avl.pop();
            ans[i] = y;
            busy.push({curr + tasks[i],y});
        }
        return ans;
    }
};