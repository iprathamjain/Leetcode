class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i=0;i<=30;i++){
            ans |= (1&n);
            ans<<=1;
            n>>=1;
        }
        ans |= (1&n);
        return ans;
    }
};