class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            vector<int> count(26, 0);

            // Count each character
            for (char c : s) {
                count[c - 'a']++;
            }

            // Convert count array into a string key
            string key;

            for (int x : count) {
                key += to_string(x) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};