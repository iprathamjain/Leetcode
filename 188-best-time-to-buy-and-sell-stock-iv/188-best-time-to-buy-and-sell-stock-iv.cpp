class Solution {
public:
    vector<vector<vector<int>>>dp;
    int f(int ind, int buy, vector<int>& prices, int k){
        if(ind==prices.size()){
            if(buy==1)
                return 0;
            else 
                return -1e9;
        }
        if(k==0){
            return 0;
        }
        if(dp[ind][buy][k]!=-1)
            return dp[ind][buy][k];
        int profit = 0;
        if(buy){
            profit = -(prices[ind]) + f(ind+1,0,prices,k);    
        }
        else{
            profit = (prices[ind]) + f(ind+1,1,prices,k-1);
        }
        
        int nottake = f(ind+1,buy,prices,k);
        
        
        return dp[ind][buy][k] = max(nottake, profit);
        
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,prices,k);
    }
};