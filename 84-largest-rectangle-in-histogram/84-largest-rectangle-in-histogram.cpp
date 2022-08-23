class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        int n=size(heights);
        
        stack<int>s1,s2;
        vector<int>nxtsmall(n);
        vector<int>prevsmall(n);

        s1.push(-1);
        for(int i=n-1;i>=0;i--){
            while(s1.top()!=-1 and heights[i]<=heights[s1.top()])
                s1.pop();
            nxtsmall[i]=s1.top();
            s1.push(i);
        }
        
        s2.push(-1);
        for(int i=0;i<n;i++){
            while(s2.top()!=-1 and heights[i]<=heights[s2.top()])
                s2.pop();
            prevsmall[i]=s2.top();
            s2.push(i);
        }
        
//         for(auto x:nxtsmall)
//             cout<<x<<" ";
//         cout<<endl;
        
//         for(auto y:prevsmall)
//             cout<<y<<" ";
        
        for(int i=0;i<n;i++){
            int curr=0;
            if(nxtsmall[i]==-1)
                nxtsmall[i]=n;
            curr=(nxtsmall[i]-prevsmall[i]-1)*heights[i];
            res=max(curr,res);
        }
        
        return res;
        // return 0;
    }
};