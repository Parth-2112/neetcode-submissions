class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;

        for(int i=0; i<s.size(); i++){
            map1[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            map2[t[i]]++;
        }
        
        if(map1.size()!=map2.size())
            return false;

        for(auto const& [key, val] : map1){
            if(val != map2[key])
                return false;
        }

        return true;
    }
};
