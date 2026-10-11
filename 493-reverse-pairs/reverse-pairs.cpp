class Solution {
public:

    long long mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;

        long long count = 0;

        // Count reverse pairs in left and right halves
        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);

        // Count cross reverse pairs
        int j = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (j <= right &&
                   (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }

            count += j - (mid + 1);
        }

        // Merge the two sorted halves
        vector<int> temp;
        int i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            nums[left + k] = temp[k];
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};