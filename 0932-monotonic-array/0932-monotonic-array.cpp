
static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {

        int f1 = 1,f2 = 1;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1])
            f1 = 0;
            if(nums[i]>nums[i+1])
            f2 = 0;
        }

        return (f1 || f2) ? true : false;
        
    }
};