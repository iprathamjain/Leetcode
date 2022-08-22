class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size();
        unordered_set<int> st;
        int cnt = 0;
        for(int i=0; i<n; i++) {
            st.insert(rolls[i]);
            if(st.size() == k) {
                cnt++;
                st.clear();
            }
        }
        return cnt + 1;
    }
};