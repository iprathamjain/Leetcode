class Solution {
public:
    bool ispal(string S)
{
    // Iterate over the range [0, N/2]
    for (int i = 0; i < S.length() / 2; i++) {
 
        // If S[i] is not equal to
        // the S[N-i-1]
        if (S[i] != S[S.length() - i - 1]) {
            // Return No
            return false;
        }
    }
    // Return "Yes"
    return true;
}
    bool isStrictlyPalindromic(int n) {
        
        for(int i=2;i<=n;i++){
            string ans = "";
            int num = i;
            while(num){
                ans+=(num%i);
                num/=i;
            }
            if(!ispal(ans))
                return false;
        }
        return true;
    }
};