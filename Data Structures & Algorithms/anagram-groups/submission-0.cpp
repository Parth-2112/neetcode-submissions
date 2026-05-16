class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> sorted_s_map;    
        vector<vector<string>> ans;

        for(const auto& s : strs){
            string sorteds = s;
            sort(sorteds.begin(),sorteds.end());

            sorted_s_map[sorteds].push_back(s);
        }

        for(auto& pair : sorted_s_map){
            ans.push_back(pair.second);
        }

        return ans;
    }
};
