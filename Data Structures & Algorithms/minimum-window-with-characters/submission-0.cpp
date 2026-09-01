class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size())
            return "";

        unordered_map<char, int> countT, countS;

        for (char c : t)
            countT[c]++;

        int have = 0;
        int need = countT.size();

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];
            countS[c]++;

            // This character's required frequency is now satisfied
            if (countT.count(c) && countS[c] == countT[c])
                have++;

            // Window is valid
            while (have == need) {

                // Update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];
                countS[leftChar]--;

                if (countT.count(leftChar) &&
                    countS[leftChar] < countT[leftChar])
                    have--;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};