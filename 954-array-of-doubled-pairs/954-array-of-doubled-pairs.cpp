class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int num : arr){
            map[num]++;
        }
        
        sort(arr.begin(), arr.end());
        
        vector<int> res;
        for(int ele: arr){
            if(map.find(ele * 2) != map.end() && map[ele] != 0 && map[ele * 2] != 0){
                map[ele]--;
                map[ele * 2]--;
                res.push_back(ele);
            }
        }
        
        for(auto i : map){
            if(i.second != 0){
                return false;
            }
        }
        
        return true; 
    }
};

// arr[1] = 2*arr[0];
// arr[3] = 2*arr[2];
// arr[5] = 2*arr[4];