class Solution {
public:
    int edgeScore(vector<int>& e) {
        long long m = LONG_MIN;
        int n = 0;
        map<long long,long long>mp;
        for(int i=0;i<e.size();i++){
            mp[e[i]]+=i;
            if(mp[e[i]]>m){
                m=mp[e[i]];
                n=e[i];
            }
            else if(mp[e[i]]==m){
                n=min(n,e[i]);
            }
        }
        return n;
    }
};