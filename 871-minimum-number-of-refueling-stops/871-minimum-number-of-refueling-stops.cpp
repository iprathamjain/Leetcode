class Solution {
public:
    int minRefuelStops(int t, int sf, vector<vector<int>>& st) {
        priority_queue<int>pq;
        
        int curr = sf;
        int i = 0;
        int ans = 0;
        int n = st.size();
        
        while(curr<t){
            while(i<n and curr>=st[i][0]){
                pq.push(st[i][1]);
                i++;
            }
            
            if(pq.empty())
                return -1;
            int tmp = pq.top();
            pq.pop();
            ans++;
            curr+=tmp;
        }
        
        return ans;
        
    }
};
//
//
//