class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int n = ranks.size();
        sort(suits.begin(), suits.end());
        if (suits.front() == suits.back())
            return "Flush";
        map<int,int> mp;
        for(int i = 0 ; i < n ; ++i) {
            mp[ranks[i]]++;
        }
        for(auto &it: mp) {
            if (it.second >= 3)
                return "Three of a Kind";
        }
        
        for(auto &it: mp) {
            if (it.second >= 2)
                return "Pair";
        }
        return "High Card";
    }
};