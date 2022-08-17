class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<string,int>mp;
        string ind[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto x:words){
            string tmp = "";
            for(auto y:x){
                tmp+=ind[y-'a'];
            }
            mp[tmp]++;
        }
        
        return mp.size();
    }
};