class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        int en = 0;
        for(auto x:energy)
            en+=x;
        en++;
        if(initialEnergy<=en)
            ans+=(en-initialEnergy);
        cout<<ans<<endl;
        
        int ind = max_element(experience.begin(),experience.end()) - experience.begin();
        cout<<"ind is:"<<ind<<endl;
        
        int t = initialExperience;
        for(int i=0;i<=ind;i++){
            if(t<=experience[i]){
                ans+=(experience[i]-t+1);
                t += (experience[i]-t+1);
                t+=experience[i];
                
            }
            else{
                t+=experience[i];
            }
        }
        
        // ans+=(t-initialExperience);
        
        
        
//         int t = 0;
//         for(int i=0;i<ind;i++){
//             t+=experience[i];
//         }
//         cout<<"t is:"<<t<<endl;
        
//         if(t+initialExperience<=experience[ind]){
//             cout<<"dfd "<<(experience[ind]-(t+initialExperience)+1)<<endl;
//             ans+=(experience[ind]-(t+initialExperience)+1);
//         }
        return ans;
    }
};