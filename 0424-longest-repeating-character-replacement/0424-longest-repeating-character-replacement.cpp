class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int left=0,maxCount=0,res=0;
        for(int right=0;right<s.size();right++){
            mp[s[right]]++;
            maxCount=max(maxCount,mp[s[right]]);
            if(right-left+1-maxCount>k){
                mp[s[left]]--;
                left++;
                if(mp[left]==0){
                    mp.erase(mp[left]);
                }
            }
            else{
                res=max(res,right-left+1);
            }
        }
        return res;
    }
};