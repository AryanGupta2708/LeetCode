class Solution {
private:
    bool check(vector<int>&piles,long long mid , long long  h){
        long long  hrs = 0 ;
        double div = 0 ;
        for(int i : piles){
            div =(double) i / mid ;
            if(div){
                hrs += div ;
                if(fmod(div,1)!= 0.000){
                    hrs+= 1 ;
                }
            }else{
                hrs += 1 ;
            }

        }
        if(hrs <= h){
            return true ;
        }
        return false ;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size() == h){
            return *(max_element(piles.begin(),piles.end()));
        }
        long long left = 1 , right = *(max_element(piles.begin(),piles.end())) , mid = 0 , ans = 0 ;
        while(left <= right){
            mid = left + (right - left)/2 ;
            if(check(piles,mid,h)){
                ans = mid ;
                right = mid - 1 ;
            }else{
                left = mid + 1 ;
            }
        }
        return ans ;
    }
};