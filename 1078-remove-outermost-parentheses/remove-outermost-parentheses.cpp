class Solution {
public:
    string removeOuterParentheses(string s) {
        int n= s.size();
        string ans="";
        int open=0, close=0 ;
        for(int i=0;i<n;i++){
            if(s[i]=='(')open++;
            else close++;            
            if(open==close){
                open=0, close=0;
                continue;
            }
            if(open!=1)ans+=s[i];
        }
        return ans;
    }
};