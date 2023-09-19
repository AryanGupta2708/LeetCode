class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> ar1(26,0);
        vector<int> ar2(26,0);

        for(int i=0;i<s.length();i++){
            ar1[s[i] - 'a']++;
        }
        for(int i=0;i<t.length();i++){
            ar2[t[i] - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(ar1[i]!=ar2[i])
            return false;

        }
        return true;


    }
};