class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        // Put all numbers into the set
        for (int num : nums) {
            st.insert(num);
        }

        int longest = 0;

        for (int num : st) {

            // Start only if num is the beginning
            // of a sequence
            if (st.find(num - 1) == st.end()) {

                int current = num;
                int length = 1;

                // Find consecutive numbers
                while (st.find(current + 1) != st.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
