class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int k = 1;

        for (int i = 1; i < nums.size(); i++) {

            // If current number is different
            // from the previous unique number
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
