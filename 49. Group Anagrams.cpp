class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;


        for(auto word : strs){
            string w = word;
            sort(w.begin(), w.end());
            map[w].push_back(word);
        }

        vector<vector<string>> result;
        for(auto item : map){
            result.push_back(item.second);
        }

        return result;
    }
};