class Solution {
public:
    string countAndSay(int n) {
         string str="1";
        
        for(int i=1;i<n;i++){
            string ans;
            int len=str.length();
            int index=0;
            while(index<len){
                char digit=str[index];
                int count=0;
                while(index<len && str[index]==digit){
                    index++,count++;
                }
                ans+=to_string(count);
                ans.push_back(digit);
            }
            str=ans;
        }
        return str;
    }
};