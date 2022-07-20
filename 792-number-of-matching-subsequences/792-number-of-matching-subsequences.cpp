// class Solution {
//     int isSubSeq(string& a, string b) {
        
//         int i = 0, j = 0;
//         int m = a.length(), n = b.length();
        
//         while (i < m && j < n) {
//             if (a[i] == b[j]) {
//                 i++; j++;
//             } else {
//                 i++;
//             }
//         }
        
//         return (j == n);
//     }
// public:
//     int numMatchingSubseq(string S, vector<string>& words) {
        
//         int c = 0;
//         unordered_map<string, int>mp;
//         for (int i = 0; i < words.size(); i++)
//             mp[words[i]]++;
            
//         for (auto it = mp.begin(); it != mp.end(); it++) {
//             if (isSubSeq(S, it->first))
//                 c += it->second;
//         }
        
//         return c;
//     }
    
    
// };


class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> charMap(26);
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            charMap[s[i] - 'a'].push_back(i);
        }
        
        int ans = words.size();
        for(auto& word : words) {
            int last = -1;
            
            for(char c : word) {
                auto& cIndexes = charMap[c - 'a'];
                auto it = upper_bound(cIndexes.begin(), cIndexes.end(), last);
                if(it == cIndexes.end()) {
                    ans--;
                    break;
                } else {
                    last = *it;
                }
            }
        }
        
        return ans;
    }
};