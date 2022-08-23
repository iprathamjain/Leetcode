class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int start = 0;
        int ans = 0;
        vector<int>prev(256,-1);
        for(int end = 0;end<n;end++){
            start = max(start,prev[s[end]]+1);
            int maxend = end-start+1;
            ans = max(ans,maxend);
            prev[s[end]] = end;
        }
        return ans;
//         if(s.size()==0)
//             return 0;
//         unordered_set<char>st;
//         int ans = 1;
//         st.insert(s[0]);
//         int t = 1;
//         int in = 0;
//         int i =1;
//         st.insert(s[0]);
//         while(i<size(s)){
//             if(st.find(s[i])==st.end()){
//                 t++;
//                 st.insert(s[i]);
//                 ans=max(ans,t);
//                 i++;
//             }
//             else{
//                 st.erase(s[in]);
//                 t--;
//                 in++;
//             }
//         }
        
//         return ans;
    }
};