class Solution {
public:
    int maxArea(vector<int>& height) {

        int max=0;

        for(int i=0,j=height.size()-1;i<j;){
            
            if(min(height[i],height[j])*(j-i)>max)
            max = min(height[i],height[j])*(j-i);

            if(height[i]>=height[j])
            j--;
            else if(height[i]<height[j])
            i++;
            



        }
        return max;
        
        
    }
};