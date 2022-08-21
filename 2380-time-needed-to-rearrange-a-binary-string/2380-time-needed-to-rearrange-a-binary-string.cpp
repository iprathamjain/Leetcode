class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int a = 0;
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=0;j+1<n;j++){
                if(s[j]=='0' and s[j+1]=='1')
                {
                    flag = true;
                    s[j]='1';
                    s[j+1] = '0';
                    j++;
                }
            }
            if(flag)
                a++;
        }
        return a;
    }
};