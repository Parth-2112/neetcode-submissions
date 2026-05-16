class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mapp;    
        vector<vector<string>> ans;

        for(const auto& s : strs){
            vector<int> count(26,0);
            for(char c : s){
                count[c-'a']++;
            }
            string unique_key = to_string(count[0]);
            for(int i=1; i<26; i++){
                unique_key += ',' + to_string(count[i]);
            }
            mapp[unique_key].push_back(s);
        }

        for(auto& pair : mapp){
            ans.push_back(pair.second);
        }

        return ans;
    }
};
