class Solution {
public:
    string removeKdigits(string num, int k) {
        string def="0";
        if(num.length()==1 and k==1)
            return def;
        //https://leetcode.com/problems/remove-k-digits/discuss/607570/C%2B%2B-solution-8ms-with-detailed-explanation
        string ans="";
        for(char &c:num)
        {
            while(ans.size() && ans.back()>c &&k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.size()||c!='0')ans.push_back(c);
        }
        while(ans.size()&&k--)           //<-------this look is to make sure we fulfil the deletion condition
        {
            ans.pop_back();
        }
        
        return (ans=="")?"0":ans;
    }
};