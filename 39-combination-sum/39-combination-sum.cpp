class Solution {
public:
    void f(int ind, vector<vector<int>>&ans,vector<int>&tmp, vector<int>& c, int t){
        if(t<0 or (ind==c.size() and t!=0))
            return;
        if(t==0){
            ans.push_back(tmp);
            return ;
        }
        
        tmp.push_back(c[ind]);
        f(ind,ans,tmp,c,t-c[ind]);
        
        tmp.pop_back();
        f(ind+1,ans,tmp,c,t);
        
        // return ans;
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>>ans;
        vector<int>tmp;
        f(0,ans,tmp,c,t);
        return ans;
    }
};