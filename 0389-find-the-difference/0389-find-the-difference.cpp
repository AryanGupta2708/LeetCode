class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> x;
        for(int i=0;i<s.length();i++){
            x[s[i]]++;
        }

        for(int i=0;i<t.length();i++){
            x[t[i]]--;
            if(x[t[i]]<0)
            return t[i];
        }

        return 'a';
        
    }
};