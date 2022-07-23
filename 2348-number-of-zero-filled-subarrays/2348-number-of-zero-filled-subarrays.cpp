class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0 ;
        long long zeroes = 0;
        for(int x: nums) {
            if (x == 0) {
                zeroes ++;
            } else {
                ans += (zeroes * (zeroes + 1))/2;
                zeroes = 0;
            }
        }
        ans += (zeroes * (zeroes + 1))/2;;
        return ans;
    }
};