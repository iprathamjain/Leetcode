class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(auto x:q){
            int f = x;
            int c = 0;
            int sum = 0;
            int i;
            for(i=0;i<nums.size();i++){
                if(sum+nums[i]<=x)
                    sum+=nums[i];
                else
                    break;
            }
            ans.push_back(i);
        }
        return ans;
    }
};

// 1 2 4 5