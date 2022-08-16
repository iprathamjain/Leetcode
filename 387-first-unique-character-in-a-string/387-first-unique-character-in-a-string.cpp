class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        map<char,int>ind;
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            mp[s[i]]++;
            ind[s[i]]=i;
        }
        int ans = 1e9;
        for(auto x:mp){
            if(x.second==1){
                ans = min(ans,ind[x.first]);
            }
        }
        if(ans==1e9)
            return -1;
        return ans;

    }
};

//d-4
//c-2
//b-2
//a-1