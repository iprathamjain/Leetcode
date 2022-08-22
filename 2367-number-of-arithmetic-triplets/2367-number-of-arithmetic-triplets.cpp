class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = size(nums);
        int c = 0;
        for(int i=0;i<n;i++){
            int a = nums[i];
            for(int j = i+1;j<n;j++){
                if(nums[j]-a==diff){
                    for(int k = j+1;k<n;k++){
                        if(nums[k]-nums[j]==diff)
                            c++;
                    }
                }
            }
        }
        return c;
    }
};