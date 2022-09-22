class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        string t = "";
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                t+=s[i];
            }
            else{
                reverse(t.begin(),t.end());
                ans+=t+" ";
                t="";
            }
        }
        reverse(t.begin(),t.end());
        ans+=t;
        return ans;
    }
};