class Solution {
    //"a"
    // e
public:
    string removeStars(string s) {
        int n = s.length();
        string ans = "";
        int c = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]>='a' and s[i]<='z')
                ans+=s[i];
            else if (s[i]=='*'){
                while(i>=0 and s[i]=='*')
                    i--, c++;
                while(i>=0 and (c) and s[i]!='*')
                    i--,--c;
                // cout<<"count is : "<<c<<endl;
                i++;
            }
            // cout<<" i is : "<<i<<endl;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};