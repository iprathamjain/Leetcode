class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        map<char,int>mp;
        for(auto x:w2){
            map<char,int>t;
            for(auto y:x){
                t[y]++;
                mp[y] = max(mp[y],t[y]);
            }
        }
        
        for(auto y:mp)
            cout<<y.first<<" "<<y.second<<endl;
        vector<string> ans;
        for(auto z:w1){
            map<char,int>t1;
            for(auto c:z){
                t1[c]++;
            }
            bool flag = true;
            for(auto tmp:mp){
                if(t1[tmp.first]<tmp.second){
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                ans.push_back(z);
        }
        
        return ans;
    }
};