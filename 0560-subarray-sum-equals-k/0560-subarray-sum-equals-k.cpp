class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Prefix sum 0 has appeared once
        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int num : nums) {

            sum += num;

            // Check if there is a previous prefix sum
            // such that current sum - previous sum = k
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
};
