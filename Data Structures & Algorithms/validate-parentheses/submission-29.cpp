class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        bool pushed = false;

        if(s.length()%2 == 1)
            return false;

        for(char& c : s){
            if(c == '[' || c == '(' || c == '{'){
                st.push(c);   
                pushed = true; 
            }
            else if(st.empty()){
                return false;
            }
            else if(c == '}' && st.top() == '{'){
                st.pop();
            }
            else if(c == ']' && st.top() == '['){
                st.pop();
            }
            else if(c == ')' && st.top() == '('){
                st.pop();
            }
            else
                return false;
        }

        if(st.empty() && pushed)
            return true;


        return false;
    }
};