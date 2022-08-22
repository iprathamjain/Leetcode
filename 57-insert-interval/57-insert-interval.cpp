class Solution {
public:
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        intervals.push_back(ni);
        if(intervals.size()<=1)
            return intervals;
        vector<vector<int>>v;
        sort(intervals.begin(),intervals.end());
        v.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=v[j][1])
                v[j][1]=max(intervals[i][1],v[j][1]);
            else
            {
                v.push_back(intervals[i]);
                j++;
            }
        }
        return v;
    }
};