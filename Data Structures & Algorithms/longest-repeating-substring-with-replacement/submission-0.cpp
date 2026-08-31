class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};

        int l = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // Characters that need to be replaced
            int changes = (r - l + 1) - maxFreq;

            while (changes > k) {
                freq[s[l] - 'A']--;
                l++;

                changes = (r - l + 1) - maxFreq;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};