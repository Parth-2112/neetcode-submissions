class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string &s : strs){
            ans += to_string(s.length()) + '#' + s ;
        }
        return ans;
    }

    vector<string> decode(string s) {
        
        vector<string> ans;
        
        int i=0;
        while(i<s.length()){            
            int j=i;
            string num="";

            while(s[j]!='#'){
                num += s[j];
                i++;
                j++;      
            }
            
            int len = stoi(num);
            i++;
            j=0;
            string ss="";
            while(j<len){
                ss += s[i];
                i++;
                j++;
            }
            ans.push_back(ss);
        }
        
        return ans;
    }
};
