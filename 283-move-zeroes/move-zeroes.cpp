class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int x = 0;

        for (int i = 0; i < nums.size() - x; i++) {
            if (nums[i] == 0) {

                for (int j = i; j < nums.size() - x - 1; j++) {
                    swap(nums[j], nums[j + 1]);
                }

                x++;
                i--;
            }
        }
    }
};