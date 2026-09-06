class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long left = 0;
        long long right = 0;

        // Minimum possible answer = largest element
        // Maximum possible answer = total sum
        for (int x : nums) {
            left = max(left, (long long)x);
            right += x;
        }

        while (left < right) {
            long long mid = left + (right - left) / 2;

            int parts = 1;
            long long sum = 0;

            for (int x : nums) {
                if (sum + x > mid) {
                    // Start a new subarray
                    parts++;
                    sum = x;
                } else {
                    sum += x;
                }
            }

            if (parts <= k) {
                // Possible to split, try smaller maximum sum
                right = mid;
            } else {
                // Need more than k subarrays
                left = mid + 1;
            }
        }

        return left;
    }
};
