class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0,right = 0;
        int count = 0,m = 0;
        vector<int>ar(100,0);

        for(;right<s.length();right++){

            ar[s[right] - ' ']++;

            while(ar[s[right] - ' ']>1){
                ar[s[left] - ' ']--;
                left++;

            }

            count = right - left + 1;

            m = max(count,m);

        }

        return m;
        
    }
};