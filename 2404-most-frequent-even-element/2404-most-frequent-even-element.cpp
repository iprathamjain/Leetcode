class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        for(auto x:nums){
            if(x%2==0)
                mp[x]++;
        }
        pair<int,int>p = {-1,-1};
        for(auto x:mp){
            if(x.second>p.second){
                p.first = x.first;
                p.second = x.second;
            }
        }
        if(p.second==-1)
            return -1;
        return p.first;
    }
};