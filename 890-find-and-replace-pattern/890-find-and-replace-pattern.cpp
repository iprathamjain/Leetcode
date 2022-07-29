class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
        vector<string> ans;
        int n= p.length();
        for(int i=0;i<w.size();i++){
            if(n!=w[i].length())
                continue;
            map<char,char>tmp;
            bool f = true;
            int arr[26];
            memset(arr,0,sizeof(arr));
            for(int j=0;j<n;j++){
                if(tmp.find(p[j])==tmp.end() and arr[w[i][j]-'a']==0){
                    tmp[p[j]] = w[i][j];
                    arr[w[i][j]-'a'] = 1;
                }
                else{
                    if(tmp[p[j]] != w[i][j]){
                        f = false; break; 
                    }
                }
            }
            if(f)
                ans.push_back(w[i]);
                
        }
        return ans;

    }
};