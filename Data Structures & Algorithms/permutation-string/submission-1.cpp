class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        int count1[26] = {0};
        int count2[26] = {0};

        // Frequency of characters in s1
        for (char c : s1) {
            count1[c - 'a']++;
        }

        int k = s1.length();

        // First window of size k
        for (int i = 0; i < k; i++) {
            count2[s2[i] - 'a']++;
        }

        if (equal(count1, count2))
            return true;

        // Slide the window
        for (int r = k; r < s2.length(); r++) {
            // Add new character
            count2[s2[r] - 'a']++;

            // Remove left character
            count2[s2[r - k] - 'a']--;

            if (equal(count1, count2))
                return true;
        }

        return false;
    }

private:
    bool equal(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
};