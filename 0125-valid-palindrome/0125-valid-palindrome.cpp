class Solution {
public:
    bool isPalindrome(string s) {

        

        int x=0,y=s.length()-1;

        while(x<y){

            if(!(isalpha(s[x]) || isdigit(s[x]))){
                x++;
                continue;
            }
            if(!(isalpha(s[y]) || isdigit(s[y]))){
                y--;
                continue;
            }

            if(tolower(s[x])!=tolower(s[y]))
            return false;

            x++;
            y--;
        }

        return true;
        
    }
};