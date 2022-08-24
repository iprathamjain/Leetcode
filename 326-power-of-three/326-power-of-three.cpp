class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n&1==0 or n==0)
            return false;
        while(n%3==0){
            n/=3;
        }
        if(n==1)
            return 1;
        return 0;
    }
};