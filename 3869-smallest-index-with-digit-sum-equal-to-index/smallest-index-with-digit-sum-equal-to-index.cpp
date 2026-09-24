class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int index = -1;
        if (nums[0] == 0) {
            return 0;
        };
        for (int i = 0; i < nums.size(); i++) {
            int total = 0;
            nums[i] = abs(nums[i]);
            while (nums[i] > 0) {

                total = total + nums[i] % 10;
                nums[i] = nums[i] / 10;
            }
            if (total == i) {
                return i;
            }

            
        }
        return index;
    }
};