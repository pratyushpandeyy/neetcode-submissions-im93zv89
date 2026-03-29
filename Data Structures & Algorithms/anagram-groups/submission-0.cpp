class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++)
        {
            string key = strs[i]; // did this because otherwise sort will sort the strs[i] also, we want to retain its behaviour 
            sort(key.begin(), key.end());
            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for (auto it : mp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};