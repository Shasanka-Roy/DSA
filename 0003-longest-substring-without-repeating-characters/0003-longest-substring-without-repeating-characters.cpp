class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            // If duplicate, remove characters from the left
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }

            // Add current character
            window.insert(s[right]);

            // Calculate current window length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
