class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        long long firstSum = 0;
        long long secondSum = 0;

        for (int i = 0; i < half; i++) {
            firstSum += nums[i];
        }

        for (int i = half; i < n; i++) {
            secondSum += nums[i];
        }

        int ans = 0;

        for (int start = 0; start < n; start++) {

            if (firstSum > secondSum) {
                ans++;
            }

            long long outgoing = nums[start];
            long long incoming = nums[(start + half) % n];

            firstSum = firstSum - outgoing + incoming;
            secondSum = secondSum - incoming + outgoing;
        }

        return ans;
    }
};
