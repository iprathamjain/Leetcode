class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        int curr = 0;
        for(int i=1;i<travel.size();i++){
            travel[i] = travel[i] + travel[i-1];
        }
        vector<pair<int,int>>m;
        vector<pair<int,int>>p;
        vector<pair<int,int>>g;
        
        for(int i=0;i<garbage.size();i++){
            string t = garbage[i];
            int mc = 0, pc = 0, gc = 0;
            for(auto x:t){
                if(x=='M'){
                    mc++;
                }
                else if(x=='P'){
                    pc++;
                }
                else{
                    gc++;
                }
            }
            if(mc)
                m.push_back({i,mc});
            if(pc)
                p.push_back({i,pc});
            if(gc)
                g.push_back({i,gc});
        }
        
        if(p.size()!=0){
            int dist = 0;
            for(auto x:p){
                    ans+=x.second;
                    dist = x.first;
                }
            if(dist!=0)
                ans+=travel[dist-1];
            }
            
    
        if(g.size()!=0){
            int dist = 0;
            for(auto x:g){
                    ans+=x.second;
                    dist = x.first;
                }
            if(dist!=0)
                ans+=travel[dist-1];
            }
        

        if(m.size()!=0){
            int dist = 0;
            for(auto x:m){
                    ans+=x.second;
                    dist = x.first;
                }
            if(dist!=0)
                ans+=travel[dist-1];
            }
            
    
        return ans;
        
        
    }
};