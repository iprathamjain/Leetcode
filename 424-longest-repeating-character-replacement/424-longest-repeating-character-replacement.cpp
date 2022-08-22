class Solution {
public:
    int maxinmap(vector<int>&arr){
        int ans = 0;
        for(int i=0;i<26;i++){
            ans=max(ans,arr[i]);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        vector<int>arr(26,0);
        int ans = 0;
        int st=0,end=0;
        while(end<s.size()){
            arr[s[end]-'A']++;
            int len = end-st+1;
            int mlen = maxinmap(arr);
            if((len-mlen)<=k){
                ans = max(ans,len);
                end++;
            }
            else{
                arr[s[st]-'A']--;
                arr[s[end]-'A']--;
                st++;
            }
        }
        
        return ans;
        
    }
};