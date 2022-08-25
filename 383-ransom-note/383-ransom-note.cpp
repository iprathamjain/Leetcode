class Solution {
public:
    bool canConstruct(string rn, string ma) {
        sort(rn.begin(),rn.end());
        sort(ma.begin(),ma.end());
        int i=0,j=0;
        while(i<rn.size() and j<ma.size()){
            if(rn[i]==ma[j])
                i++,j++;
            else
                j++;
        }
        if(i==rn.size())
            return true;
        return false;
    }
};