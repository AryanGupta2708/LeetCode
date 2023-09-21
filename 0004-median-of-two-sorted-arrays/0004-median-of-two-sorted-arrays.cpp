class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> x = nums1;
        x.insert(x.end(),nums2.begin(),nums2.end());

        sort(x.begin(),x.end());

        if(x.size()%2==0){
            double z = double(x[x.size()/2] + x[x.size()/2 -1])/2;
            return z;
        }
        return x[x.size()/2];
        
    }
};