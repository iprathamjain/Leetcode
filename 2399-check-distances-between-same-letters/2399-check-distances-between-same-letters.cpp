class Solution {
public:
    bool checkDistances(string s, vector<int>& d) {
        map<char,vector<int>>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        for(auto x:mp){
            vector<int>t =x.second;
            cout<<t[0]<<" "<<t[1]<<endl;
            int res = abs(t[0]-t[1])-1;
            if(d[x.first-'a']!=res)
                return false;
        }
        
        return true;
    }
};