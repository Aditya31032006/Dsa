class Solution {
public:

    void solve(vector<int>& candidates, int target, int index,
               vector<int>& current, vector<vector<int>>& ans) {

        // Target achieved
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicate values at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since array is sorted, no further value can work
            if (candidates[i] > target) {
                break;
            }

            // Choose
            current.push_back(candidates[i]);

            // i + 1 because every number can be used only once
            solve(
                candidates,
                target - candidates[i],
                i + 1,
                current,
                ans
            );

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> current;

        // Sorting is important for:
        // 1. Skipping duplicates
        // 2. Breaking when candidates[i] > target
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, current, ans);

        return ans;
    }
};