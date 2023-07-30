class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1){
            return 1;
        }
        string ans="";
        int count=1;
        int i=0;
        for(i=0;i<chars.size()-1;i++){
            if(chars[i]==chars[i+1]){
                count++;
            }
            else{
                if(count>1){
                ans+=chars[i]+to_string(count);
                count=1;
                }
                else{
                    ans+=chars[i];
                    count=1;
                }
            }
        }
        if(count>1){
            ans+=chars[i]+to_string(count);
        }
        else{
            ans+=chars[i];
        }
        for(int i=0;i<ans.length();i++){
            chars[i]=ans[i];
        }
        return ans.length();
    }
};