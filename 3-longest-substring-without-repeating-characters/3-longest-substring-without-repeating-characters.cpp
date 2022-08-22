class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        set<char>st;
        int ans = 1;
        st.insert(s[0]);
        int t = 1;
        int in = 0;
        int i =1;
        st.insert(s[0]);
        while(i<size(s)){
            if(st.find(s[i])==st.end()){
                t++;
                st.insert(s[i]);
                ans=max(ans,t);
                i++;
            }
            else{
                st.erase(s[in]);
                t--;
                in++;
            }
        }
        
        return ans;
    }
};