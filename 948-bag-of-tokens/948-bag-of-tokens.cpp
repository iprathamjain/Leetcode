class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int pow) {
        int ans = 0;
        int score = 0;
        sort(t.begin(),t.end());
        int i=0, j=t.size()-1;
        while(i<=j){
            if(pow>=t[i]){
                cout<<"score up"<<endl;
                pow-=t[i];
                score++;
                ans = max(ans, score);
                i++;
            }
            else if(score>=1){
                cout<<"score down"<<endl;
                pow+=t[j];
                score--;
                ans = max(ans, score);
                j--;
            }
            else
                return ans;
        }
        return ans;
    }
};

//score more 
//power less

//pow<token i -- lose token power // gain 1 score
//score>=1 -- gain token power // lose 1 score