class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        if(s.length()%2!=0)
        return false;

        for(auto i : s){
            if(i=='(' || i=='{' || i=='['){
                st.push(i);
                continue;
            }
            else if(st.size()==0)
            return false;

            else if(i=='}' && st.top()=='{'){
                st.pop();
            }
            else if(i==')' && st.top()=='('){
                st.pop();
            }
            else if(i==']' && st.top()=='['){
                st.pop();
            }
            else return false;
        }

        if(st.size()==0)
        return true;

        return false;

        
    }
};