class Solution {
public:
        int firstOcc(int start,int end,int k,vector<int> & v){
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(v[mid]==k){
                ans=mid;
                end=mid-1;
            }
            else if(v[mid]<k)
                start=mid+1;
            else
                end=mid-1;
        }
        return ans;
    }
    
    int LastOcc(int start,int end,int k,vector<int> & v){
         int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(v[mid]==k)
            {
                ans=mid;
                start=mid+1;
            }
            else if(v[mid]<k)
                start=mid+1;
            else
                end=mid-1;
        }
        return ans;
    }
    
    
    
    vector<int> searchRange(vector<int>& v, int k) {
       vector<int> ans(2,0);
        ans[0]=firstOcc(0,v.size()-1,k,v);
        ans[1]=LastOcc(0,v.size()-1,k,v);
        return ans;
    }
};