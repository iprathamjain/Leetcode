class Solution {
public:
    static bool cmp(pair<int,int>&a1, pair<int,int>&a2){
        return a1.second > a2.second;
    }
        int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int,int>mp;
        for(auto x:arr)
            mp[x]++;
        int t = n/2;
        vector<pair<int,int> >v;
        cout<<"t is "<<t<<endl;
        for(auto x:mp){
            v.push_back({x.first,x.second});
        }
        sort(v.begin(),v.end(),cmp);
        for(auto x:v)
            cout<<x.first<<" "<<x.second<<endl;
        int curr=0;
        int ans = 0;
        for(int i=0;i<v.size();i++){
            if(curr+v[i].second>=n/2){
                ans++;
                break;
            }
            else{
                curr+=v[i].second;
                ans++;
            }
            cout<<"curr is "<<curr<<endl;
        }
        return ans;
    }
};