class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int t=0;
        for(int i=1;i<colors.length();i++){
            if(colors[i]==colors[i-1]){
                int a = min(neededTime[i],neededTime[i-1]);
                t+=a;
                if(neededTime[i]<=neededTime[i-1])
                    neededTime[i]=neededTime[i-1];
            }
        }
        return t;
    }
};