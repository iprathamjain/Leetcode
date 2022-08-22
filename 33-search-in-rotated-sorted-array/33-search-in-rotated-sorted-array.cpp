class Solution {
public:
    int search(vector<int>& arr, int x) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(arr[mid]==x) {return mid;}
            if(arr[low]<=arr[mid])
            {
                if(x>=arr[low] and x<=arr[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else
            {
                if(x>=arr[mid] and x<=arr[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};