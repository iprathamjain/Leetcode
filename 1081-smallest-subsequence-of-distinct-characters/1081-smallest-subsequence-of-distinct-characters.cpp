class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]] = i;
        }
        cout<<"fd";
        string ans = "";
        vector<bool>vis(26,false);
        for(int i=0;i<s.size();i++){
            cout<<ans<<endl;
            if(vis[s[i]-'a'])
                continue;
            while(!ans.empty() and ans.back()>s[i] and mp[ans.back()]>i){
                
                vis[ans.back()-'a'] = false;
                ans.pop_back();
            }
            
            vis[s[i]-'a'] = true;
            ans.push_back(s[i]);
        }
        return ans;
    }
};

