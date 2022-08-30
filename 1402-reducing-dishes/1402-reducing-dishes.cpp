class Solution {
private:
    int dp[501][501];
	int f(int i, int num, vector<int> &a) {
		if (i == a.size()) return 0;
        if(dp[i][num] != -1) return dp[i][num];
		int take = a[i] * num + f(i + 1, num + 1, a);
		int not_take = f(i + 1, num, a);
		return dp[i][num] = max(take, not_take);
	}
public:
	int maxSatisfaction(vector<int>& a) {
        memset(dp, -1, sizeof(dp));
        sort(a.begin(), a.end());
		return f(0, 1, a);
	}
};