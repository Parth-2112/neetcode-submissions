class Solution {
public:

    string encode(vector<string>& strs) {
        
        string encodedAns = "";
        for(auto &s : strs){
            int slen = s.length();
            encodedAns += to_string(slen) + ':' + s;
        }
        return encodedAns;
    }

    vector<string> decode(string s) {
        
        vector<string> ans;
        string ds = "";
        int i=0;

        while( i<s.size() ){
            
            string slen = "";
            
            while(s[i]!=':'){
                slen += s[i];
                i++;
            }
            i++;
            
            int len = stoi(slen);
            
            while(len>0){
                ds += s[i];
                i++;
                len--;
            }
            ans.push_back(ds);
            ds = "";
        }
        return ans;
    }
};
