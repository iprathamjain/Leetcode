class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==2 or n<=0)
            return false;
        int t = n;
        int pos = 1;
        while(t){
            if(t&1)
                break;
            pos++;
            t>>=1;
        }
        
        return ((n&(n-1))==0 and pos%2==1);
    }
};
//