class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         long long int maxp = INT_MIN, prod = 1;
//         int n = size(arr);
// 	    for(int i=0;i<n;i++){
// 	        prod *= arr[i];
// 	        maxp = max(maxp, prod);
// 	        if(prod == 0){
// 	            prod = 1;
// 	        }
// 	    }
	    
// 	    prod = 1;
// 	    for(int i=n-1;i>=0;i--){
// 	        prod *= arr[i];
// 	        maxp = max(maxp, prod);
// 	        if(prod == 0){
// 	            prod = 1;
// 	        }
// 	    }
	    
// 	    return maxp;
        
        // in one loop
        int n = nums.size(), res = nums[0], l = 1, r = 1;
        for (int i = 0; i < n; i++) {
            l =  (l) * nums[i];
            r =  (r) * nums[n - 1 - i];
            res = max(res, max(l, r));
            if(l==0)l=1;
            if(r==0)r=1;
        }
        return res;
    }
};