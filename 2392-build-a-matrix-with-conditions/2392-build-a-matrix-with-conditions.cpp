class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        int n = row.size();
        int m = col.size();

        vector<vector<int>> rowE(k+1);
        vector<int> indeg(k+1,0);
        for(auto x:row){
            rowE[x[0]].push_back(x[1]);
            indeg[x[1]]++;
        }
        queue<int> que;
        for(int i=1;i<=k;i++){
            if(indeg[i]==0) que.push(i);
        }
        vector<int>roww;
        
        int cntr = 0;
        while(!que.empty()){
            int top = que.front();que.pop();
            cntr++;
            roww.push_back(top);
            for(auto x:rowE[top]){
                indeg[x]--;
                if(indeg[x]==0) que.push(x);
            }
        }
        
        if(cntr!=k)
            return {};
        vector<vector<int>> colE(k+1);
        fill(indeg.begin(),indeg.end(),0);
        for(auto x:col){
            colE[x[0]].push_back(x[1]);
            indeg[x[1]]++;
        }
        
        for(int i=1;i<=k;i++){
            if(indeg[i]==0) que.push(i);
        }
        
        int cntc = 0;
        vector<int>coll;
        while(!que.empty()){
            int top = que.front();que.pop();
            cntc++;
            coll.push_back(top);
            for(auto x:colE[top]){
                indeg[x]--;
                if(indeg[x]==0) que.push(x);
            }
        }
        
        if(cntc!=k)
            return {};
        
        cout<<"size is : "<<roww.size()<<endl;
        for(auto x:roww)
            cout<<x<<" ";
        cout<<endl;
        
        for(auto x:coll)
            cout<<x<<" ";
        cout<<endl;
        
        // cout<<"k is : "<<k<<endl;
        vector<pair<int,int>>inde(k+1);
        for(auto x:inde){
            x.first = -1;
            x.second = -1;
        }
        
        for(int i=0;i<k;i++){
            inde[roww[i]].first = i;
        }
        
        for(int i=0;i<k;i++){
            inde[coll[i]].second = i;
        }
        
        for(int i=1;i<=k;i++){
            if(inde[i].first==-1 || inde[i].second==-1) return {};
        }
        
        vector<vector<int>> mat(k,vector<int>(k,0));
        
        for(int i=1;i<=k;i++){
            mat[inde[i].first][inde[i].second] = i;
        }
        
        return mat;
    }
};