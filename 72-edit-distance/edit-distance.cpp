
class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length();
        int n = word2.length();
        
        std::vector<int> prev(n + 1, 0);
        for (int j = 0; j <= n; ++j) prev[j] = j;
        
        for (int i = 1; i <= m; ++i) {
            std::vector<int> curr(n + 1, 0);
            curr[0] = i;
            
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1 + std::min({prev[j],      // Delete
                                            curr[j - 1],  // Insert
                                            prev[j - 1]});// Replace
                }
            }
            prev = std::move(curr);
        }
        
        return prev[n];
    }
};