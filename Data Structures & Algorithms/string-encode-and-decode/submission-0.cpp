class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for (string s : strs) {
            res += to_string(s.size()) + "#" + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

            // Get length
            int len = stoi(s.substr(i, j - i));

            // Move past '#'
            j++;

            // Extract string
            res.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return res;
    }
};