class Solution {
public:

    void mergeSort(
        vector<pair<int, int>>& nums,
        vector<int>& count,
        int left,
        int right
    ) {

        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, count, left, mid);
        mergeSort(nums, count, mid + 1, right);

        vector<pair<int, int>> temp;

        int i = left;
        int j = mid + 1;

        int rightSmaller = 0;

        while (i <= mid && j <= right) {

            if (nums[j].first < nums[i].first) {

                temp.push_back(nums[j]);

                rightSmaller++;
                j++;

            }
            else {

                count[nums[i].second] += rightSmaller;

                temp.push_back(nums[i]);

                i++;
            }
        }

        while (i <= mid) {

            count[nums[i].second] += rightSmaller;

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
    }


    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<int> count(n, 0);

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, count, 0, n - 1);

        return count;
    }
};