class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Find peak
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int peak = left;

        // Search increasing part
        int ans = binarySearchIncreasing(
            mountainArr, target, 0, peak
        );

        if (ans != -1)
            return ans;

        // Search decreasing part
        return binarySearchDecreasing(
            mountainArr, target, peak + 1, n - 1
        );
    }

private:
    int binarySearchIncreasing(
        MountainArray &arr, int target, int left, int right
    ) {
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr.get(mid) == target)
                return mid;

            if (arr.get(mid) < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

    int binarySearchDecreasing(
        MountainArray &arr, int target, int left, int right
    ) {
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr.get(mid) == target)
                return mid;

            if (arr.get(mid) > target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};
