class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(),satisfaction.end());
        int i=0,flag = 0,sum=0;
        int lulul=0;
        int lulul2=0;
        int x=0;
        
        if(satisfaction[satisfaction.size()-1]<0){
            return 0;
        }
        while(satisfaction[x]<0){
            lulul=0;
            lulul2=0;
            for(int j=satisfaction.size()-1;j>0;j--){
                
                lulul2+=satisfaction[j]*j;
                lulul+=satisfaction[j]*(j+1);
            }
            lulul+=satisfaction[0];
            
            
            
           if(lulul2>lulul){satisfaction.erase(satisfaction.begin());}
           else x++; 
        }
        
        
        sum=0;
        for(int i=0;i<satisfaction.size();i++){
            sum+=satisfaction[i]*(i+1);
        }

        return sum;
        
    }
};