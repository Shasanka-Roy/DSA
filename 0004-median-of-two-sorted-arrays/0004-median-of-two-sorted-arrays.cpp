class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();

        int left = 0;
        int right = n;

        while (left <= right) {
            // Partition nums1
            int cut1 = left + (right - left) / 2;

            // Partition nums2 so left side has half the elements
            int cut2 = (n + m + 1) / 2 - cut1;

            int left1  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == n) ? INT_MAX : nums1[cut1];

            int left2  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                if ((n + m) % 2 == 1) {
                    return max(left1, left2);
                }

                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            // nums1 partition is too far right
            if (left1 > right2) {
                right = cut1 - 1;
            }
            // nums1 partition is too far left
            else {
                left = cut1 + 1;
            }
        }

        return 0.0;
    }
};
