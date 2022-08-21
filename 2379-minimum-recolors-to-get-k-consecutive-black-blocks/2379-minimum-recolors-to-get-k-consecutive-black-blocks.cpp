class Solution {
public:
    int minimumRecolors(string b, int k) {
        int n = b.size();
        int ans = 1e9;
        for(int i=0;i<=n-k;i++){
            int j = k;
            int t = 0;
            while(j--){
                if(b[j+i]=='W')
                    t++;
            }
            ans = min(ans,t);
        }
        return ans;
    }
};