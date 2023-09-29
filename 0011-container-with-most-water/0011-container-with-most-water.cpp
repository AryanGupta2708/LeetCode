class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0,right = height.size()-1,newvol = 0,vol = 0;

        while(left<right){
            newvol = (min(height[left],height[right]))*(right-left);
            vol = max(vol,newvol);

            if(height[left]<height[right]){
                left++;
                
            }
            else{
                right--;
                
            }

            
        }

        return vol;


        
    }
};