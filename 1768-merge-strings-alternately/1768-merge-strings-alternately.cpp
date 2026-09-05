class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string result;

        int i = 0;
        int j = 0;

        while (i < word1.size() || j < word2.size()) {

            // Take character from word1
            if (i < word1.size()) {
                result += word1[i];
                i++;
            }

            // Take character from word2
            if (j < word2.size()) {
                result += word2[j];
                j++;
            }
        }

        return result;
    }
};
