class Solution {
public:
    //0(n) one traversal only. 2 pointer
    int trap(vector<int>& A) {
        int n = A.size();
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
    
    // 0(3n) 
//     int trap(vector<int>& arr) {
//         int res=0;
//         int n = arr.size();
//         int lmax[n],rmax[n];
//         lmax[0]=arr[0];
//         for(int i=1;i<n;i++)
//             lmax[i]=max(arr[i],lmax[i-1]);
//         rmax[n-1]=arr[n-1];
//         for(int i=n-2;i>=0;i--)
//             rmax[i]=max(arr[i],rmax[i+1]);
//         for(int i=1;i<n-1;i++)
//             res+=min(lmax[i],rmax[i])-arr[i];
//         return res;
        
//     }
};