class Solution {
public:
    string decodeAtIndex(string s, int k) {

        int n = s.length();
        long size = 0;
        

        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                size = size*(s[i] - '0');
            }
            
            if(isalpha(s[i])){
                size++;
            }
            
        }

        for(int i=n-1;i>=0;i--){
            
            k = k % size;

            if(k==0 && isalpha(s[i])|| k==size && isalpha(s[i])){
                char c = s[i];
                string temp = "";
                temp=temp+c;
                return temp;
            }
            if(isdigit(s[i])){
                size = size / (s[i]-'0');
            }
            else
                size--;
        

        }

        return ("lul");
        
    }
};