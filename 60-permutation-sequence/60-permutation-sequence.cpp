class Solution {
public:
    
	// this function is called to calculate possible number
	// of permutations for a given point through which, we will 
	// calculate number of possible groups
	
    int fact(int num)
    {
        if(num==0)
            return 1 ;
        
        return num*fact(num-1);
    }
    
    string ans ;
    int count = 0 ;
    
    void permute(string str , int k, string finalAns)
    {
        
        if(str.length()==0)
        {
            ans = finalAns ;
            return ;
        }
        
        int number = str.length() - 1 ;
        int factNum = fact(number) ;
        
        for(int ctr = 0 ; ctr < str.length() ; ctr++ )
        {
            
            if( factNum < k )
            {
                k-=factNum;
                continue;
            }
            
            string sub = str.substr(0,ctr) + str.substr(ctr+1);
            permute(sub,k,finalAns+str[ctr]);
            break;
            
        }
        
    }
    
    string getPermutation(int n, int k) {
        
        string str = "" ;
        
        for(int ctr = 1 ; ctr <=n ; ctr++ )            
            str+=to_string(ctr);
        
        permute(str,k,"");
        
        return ans ;
        
    }
};