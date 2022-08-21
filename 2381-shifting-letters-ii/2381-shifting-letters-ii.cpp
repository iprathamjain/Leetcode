class Solution {
public:
    void add(int arr[], int N, int lo, int hi, int val)
    {
        arr[lo] += val;
        if (hi != N - 1)
           arr[hi + 1] -= val;
    }

    //  Utility method to get actual array from operation array
    void updateArray(int arr[], int N)
    {
        //  convert array into prefix sum array
        for (int i = 1; i < N; i++)
            arr[i] += arr[i - 1];
    }

    //  method to print final updated array
    // void printArr(int arr[], int N)
    // {
    //     updateArray(arr, N);
    //     for (int i = 0; i < N; i++)
    //         cout << arr[i] << " ";
    //     cout << endl;
    // }
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int arr[50001];
        memset(arr,0,sizeof(arr));
        for(auto x:shifts){
            int t = -1;
            if(x[2]==0)
                t = -1;
            else 
                t = 1;
                
            add(arr, 50001, x[0], x[1], t);
            // for(int i=x[0];i<=x[1];i++){
            //     if(x[2]==1)
            //         arr[i]++;
            //     else
            //         arr[i]--;
            //     // cout<<"dd";
            // }
        }
        updateArray(arr, 50001);
        for(int i=0;i<s.size();i++)
            cout<<arr[i]<<" ";
        
        for(int i=0;i<s.size();i++){
            if(arr[i]==0)
                continue;
            else if(arr[i]<0){
                int t = ((s[i]-'a')+(arr[i]))%26;
                if(t<0)
                    t = 26 + t;
                s[i] = 'a' + t;
                // cout<<t<<" ";
                // cout<<"ff"<<endl;
            }
            else if(arr[i]>0){
                int t = ((s[i]-'a')+(arr[i]))%26;
                s[i] = 'a' + t;
                // cout<<"GG"<<endl;
                // cout<<t<<" ";
            }
        }
        return s;
        
    }
};