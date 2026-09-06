class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            // Add current character
            freq[s[right] - 'A']++;

            // Most frequent character in the window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Characters we need to replace
            int replacements = (right - left + 1) - maxFreq;

            // Too many replacements -> shrink window
            if (replacements > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update answer
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
