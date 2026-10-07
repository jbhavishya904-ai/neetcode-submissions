class Solution {
public:
    vector<string> result;

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> phone = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string current;

        backtrack(0, digits, phone, current);

        return result;
    }

    void backtrack(int index, string &digits,
                   vector<string> &phone, string &current) {

        // All digits have been processed
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = phone[digits[index] - '0'];

        for (char ch : letters) {
            current.push_back(ch);

            backtrack(index + 1, digits, phone, current);

            current.pop_back();
        }
    }
};