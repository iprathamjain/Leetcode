class Solution {
public:
    vector<int>ans;
    void f(int ind, int n, int k, string s,char prev){
        if(ind==n)
        {
            int n = stoi(s);
            ans.push_back(n);
            return ;
        }
        if(k==0){
            if(prev+k-'0'<=9){
                s+=(prev+k);
                f(ind+1,n,k,s,prev+k);
                s.pop_back();
            }
        }
        else{
            if(prev+k-'0'<=9){
                s+=(prev+k);
                f(ind+1,n,k,s,prev+k);
                s.pop_back();
            }
            if(prev-k-'0'>=0){
                s+=(prev-k);
                f(ind+1,n,k,s,prev-k);
                s.pop_back();
            }   
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(char i='1';i<='9';i++){
            string s = "";
            s+=i;
            f(1,n,k,s,i);
        }
        // vector<int>
        return ans;
    }
};

// 2 0
//

// 1 8 1
// 2 9 2
// 7 0 7
// 8 1 8
// 9 2 9