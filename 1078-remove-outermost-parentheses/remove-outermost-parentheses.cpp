class Solution {
public:
    string removeOuterParentheses(string s) {
        int n= s.size();
        string ans="";
        int open=1, close=0, start=0;
        for(int i=1;i<n;i++){
            if(s[i]=='(')open++;
            else close++;
            if(open==close){
                ans+=s.substr(start+1,i-start-1);
                start=i+1;
            }
        }
        return ans;
    }
};