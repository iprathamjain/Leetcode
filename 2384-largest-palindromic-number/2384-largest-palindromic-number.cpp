class Solution {
public:
    
    string largestPalindromic(string num) {
        vector<int>mp(10,0);
        for(int i=0;i<num.length();i++)
            mp[num[i]-'0']++;
        string a;
        for(int i=9;i>=0;i--){
                for(int j=0;j<mp[i]/2;j++){
                    a += char(48+i);
                }
        }
        
        string b=a;
        reverse(b.begin(),b.end());
        
        for(int i=9;i>=0;i--){
            if(mp[i]%2){
                a+=char(48+i);
                break;
            }
        }
        // cout<<t<<endl;
        
        a+=b;
        
        if(a[0]=='0'){
            string d;
            d+=a[a.length()/2];
            return d;
        }
        
        return a ;
    }
};