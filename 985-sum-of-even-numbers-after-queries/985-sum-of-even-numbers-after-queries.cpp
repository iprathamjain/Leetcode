class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> ans;
        int sum = 0;
        for(auto &x:nums)
            if(x%2==0)
                sum+=x;
        //queries[i] = [vali, indexi].
        for(auto x:q){
            if(nums[x[1]]%2==0){
                if((nums[x[1]]+x[0])%2==0){
                    sum+=+x[0];
                }
                else{
                    sum-=nums[x[1]];
                }
                nums[x[1]] += x[0];
            }
            else{
                if((nums[x[1]]+x[0])%2==0){
                    sum+=(nums[x[1]]+x[0]);
                }
                nums[x[1]] += x[0];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};