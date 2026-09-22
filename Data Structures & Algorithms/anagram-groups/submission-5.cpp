
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mapp;
        vector<vector<string>> res;

        for(const auto &s : strs){
            
            vector<int> strset(26,0);
            
            for(int i=0; i<s.length(); i++){
                strset[s[i] - 'a']++;    
            }
            
            string str = to_string(strset[0]);
            
            for(int i=1; i<26; i++){
                str += ',' + to_string(strset[i]);                
            }
            mapp[str].push_back(s);
        }

        for(const auto &p : mapp){
            res.push_back(p.second);
        }

        return res;
    }
};
