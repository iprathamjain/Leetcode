class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        if (n == 0 or m==0)
            return 0;
   
        int smallest = mat[0][0], largest = mat[n - 1][m - 1];
        if (x < smallest || x > largest)
            return 0;

        // set indexes for top right element
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            if (mat[i][j] == x)
            {
                return 1;
            }
            if (mat[i][j] > x)
                j--;

            // Check if mat[i][j] < x
            else
                i++;
        }
        return 0;
    }
};