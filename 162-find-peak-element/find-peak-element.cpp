class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Going uphill → peak is on the right
                left = mid + 1;
            }
            else {
                // Going downhill → mid could be the peak
                right = mid;
            }
        }

        return left;
    }
};