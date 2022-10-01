class Solution {
public:
    int f(int ind, string &s,vector<int>&dp){
        if(ind >= size(s))
            return 1;
        if(s[ind] == '0')
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int one = f(ind+1,s,dp);
        int two = 0;
        if(ind<size(s)-1 and stoi(s.substr(ind,2))<=26){
                two = f(ind+2,s,dp);
        }
        return dp[ind] = (one+two);
        
    }
    
    // 1 1 1 0 6
    
    int numDecodings(string s) {
        int n = size(s);
        vector<int>dp(n+1,-1);
        return f(0,s,dp);
        return 0;
        
    }
};