class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count=0,y=1;

        for(int i=0;i<arr.size();i++){
            while(arr[i]!=y && count!=k){
                y++;
                count++;

            }
            if(count==k)
            return y-1;
            else y++;
        }
        return k + arr[arr.size()-1] - count;
        
    }
};