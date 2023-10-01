class Solution {
public:
    string reverseWords(string s) {

        string temp;
        int flag = 0;

        for(int i=0;i<s.length();i++){
            while(s[i]!=' ' && i<s.length()){
                i++;
            }
             reverse(s.begin() + flag, s.begin() + i);
             flag = i+1;
        }

        return s;
        
    }
};