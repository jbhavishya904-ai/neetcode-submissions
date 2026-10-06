class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;

    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }
        return true;
    }

    void backtrack(string s, int start) {
        // If we reached the end, store this partition
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }

        // Try every possible substring
        for (int end = start; end < s.size(); end++) {

            // Only choose it if it is a palindrome
            if (isPalindrome(s, start, end)) {

                temp.push_back(s.substr(start, end - start + 1));

                // Continue from the next character
                backtrack(s, end + 1);

                // Undo the choice
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return ans;
    }
};