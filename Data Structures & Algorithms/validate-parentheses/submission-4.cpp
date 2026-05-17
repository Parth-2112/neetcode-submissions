class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        bool pushed = false;
        
        if(s.size()%2 == 1)
            return false;

        for(char c : s){
            
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);               
                pushed = true;
            }
            else if(c==')' || c==']' || c=='}'){
                
                if(st.empty()) return false;
                char top = st.top(); 
                
                if(top=='(' && c==')'){
                    st.pop();
                }
                else if(top=='[' && c==']'){
                    st.pop();
                }
                else if(top=='{' && c=='}'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else
                return false;
        }

        if(st.size() == 0 && pushed){
            return true;
        }

        return false;
    }
};