class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       int n = nums.size(); 
        int ans = 1; 
        int j = 1, i = 0; 
        while(j<n){ 
            bool y = true; 
            for(int k=j-1;k>=i; k--){ 
                if(nums[j] & nums[k]){ 
                    y = false; 
                    break; 
                } 
            } 
            if(y){ 
                ans = max(ans,j-i+1); 
                j++; 
            }else{
                i++; 
                if(i==j)
                    j++;
            } 
        } 
        return ans; 
    }
};