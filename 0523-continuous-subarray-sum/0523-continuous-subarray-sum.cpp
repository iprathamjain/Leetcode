class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefSum = 0;
	    unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i=0; i<nums.size(); i++)
        {
            prefSum += nums[i];
            int r = prefSum%k;

            if(mp.find(r) == mp.end()) 
            {
                mp[r] = i;
            }
            else if(i-mp[r]>1)
                return true;
        }

        return false;
    }
};