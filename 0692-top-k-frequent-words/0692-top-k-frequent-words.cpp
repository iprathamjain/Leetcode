class Solution {
public:
    struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,MyComp>pq;
        unordered_map<string,int>mp;
        for(auto x:words){
            mp[x]++;
        }
        
        for(auto z:mp){
            pq.push({z.second,z.first});
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);            
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};