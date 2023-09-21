class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> total;
        for(auto& i : nums1) {
            total.push_back(i);
        }
        for(auto& j : nums2) {
            total.push_back(j);
        }
        std::sort(total.begin(), total.end());

        int size = total.size();
        if(size % 2 == 0) {
            return (total[size/2-1]+total[size/2])/2.0;
        }
        else {
            return (total[size/2]);
        }
         
    }
};