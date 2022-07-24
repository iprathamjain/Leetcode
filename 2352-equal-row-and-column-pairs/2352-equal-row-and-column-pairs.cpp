class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> m;
        
        for(int i=0;i<grid.size();i++)
        {
             m[grid[i]]++;
        }
        
        int ans=0;
        set<vector<int>>s;
        
        for(int j=0;j<grid[0].size();j++)
        {
            vector<int>t;
            for(int i=0;i<grid.size();i++)
            {
                t.push_back(grid[i][j]);
            }
            ans+=m[t];
        }
        return ans;
    }
};