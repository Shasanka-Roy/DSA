class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        // Count characters in s1
        for (char c : s1) {
            count1[c - 'a']++;
        }

        int windowSize = s1.length();

        // First window
        for (int i = 0; i < windowSize; i++) {
            count2[s2[i] - 'a']++;
        }

        if (count1 == count2)
            return true;

        // Slide the window
        for (int right = windowSize; right < s2.length(); right++) {

            // Add new character
            count2[s2[right] - 'a']++;

            // Remove left character
            int left = right - windowSize;
            count2[s2[left] - 'a']--;

            if (count1 == count2)
                return true;
        }

        return false;
    }
};
