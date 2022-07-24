class FoodRatings {
public:
        unordered_map<string,set<pair<int,string>>>a;
        unordered_map<string,string>b;
        unordered_map<string,int>c;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

        int n = foods.size();
        for(int i=0;i<n;i++){
            b[foods[i]] = cuisines[i];
            a[cuisines[i]].insert({-1*ratings[i],foods[i]});
            c[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cus = b[food];
        int rat = c[food];
        a[cus].erase({-1*rat,food});
        a[cus].insert({-1*newRating,food});
        c[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto x = *(a[cuisine].begin());
        return x.second;
    }
};
