class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 1;
        int n = nums.size() ;
        if(n==0 or n==1)
            return n;
        unordered_set<int>s;
        for(auto x:nums){
            s.insert(x);
        }
        
        for(auto x:nums){
            int t = 1;
            int b = x;
            if(s.find(b-1)==s.end()){
                b++;
                while(s.find(b++)!=s.end()){
                    t++;
                }
                ans = max(ans,t);
            }
        }
        
        return ans;
    }
};