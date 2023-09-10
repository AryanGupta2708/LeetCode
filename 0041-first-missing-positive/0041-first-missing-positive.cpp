class Solution {
public:
    int findind(vector<int> &nums,int n){
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return j;
    }
    int findpos(vector<int> &nums,int size){
        for(int i=0;i<size;i++){
            int x=abs(nums[i]);
            if(x-1<size && nums[x-1]>0) nums[x-1]=-nums[x-1];
        }
        for(int i=0;i<size;i++){
            if(nums[i]>0) return i+1;
        }
        return size+1;
    }
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int ind=findind(nums,n);
        return findpos(nums,ind);
    }
};