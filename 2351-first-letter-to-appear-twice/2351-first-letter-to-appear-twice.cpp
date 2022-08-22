class Solution {
public:
    char repeatedCharacter(string s) {
        int arr[26];
        memset(arr,-1,sizeof(arr));
        for(auto x:s){
            if(arr[x-'a']==-1)
                arr[x-'a']=1;
            else
                return x;
        }
        return 'a';
    }
};