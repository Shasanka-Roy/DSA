class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Count frequency of each number
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // bucket[i] contains numbers that appear i times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& pair : freq) {
            int num = pair.first;
            int count = pair.second;

            bucket[count].push_back(num);
        }

        // Get k most frequent elements
        vector<int> result;

        for (int i = nums.size(); i >= 1 && result.size() < k; i--) {

            for (int num : bucket[i]) {
                result.push_back(num);

                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
    }
};
