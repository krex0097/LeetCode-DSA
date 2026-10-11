class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        unordered_map<char, int>mp;        
        int i=0,j =0, mx=0;
        while(j<n){
            char c=s[j];
            mp[c]++;
            while(mp[c]>1){
                mp[s[i]]--;
                i++;
            }
            mx=max(mx, j-i+1);
            j++;
        }
        return mx;
    }
};