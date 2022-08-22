class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto x:s){
            if(st.empty())
                st.push(x);
            else if((st.top()=='(' and x==')') or (st.top()=='{' and x=='}') or (st.top()=='[' and x==']'))
                st.pop();
            else 
                st.push(x);
        }
        return (st.size()==0);
    }
};