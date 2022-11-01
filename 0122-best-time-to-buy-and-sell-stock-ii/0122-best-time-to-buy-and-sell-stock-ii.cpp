class Solution {
public:
    int maxProfit(vector<int>& p) {
        int num = 0;
        
        for(int i=1;i<p.size();i++){
                        
            if(p[i-1]<p[i]){
                
             num = num + p[i]-p[i-1];   
                
            }
        }
     return num;   
    }
};