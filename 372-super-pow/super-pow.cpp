class Solution {
public:

    int power(int a, int b) {
        int result = 1;

        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % 1337;
            }

            a = (a * a) % 1337;
            b /= 2;
        }

        return result;
    }

    int superPow(int a, vector<int>& b) {
        a %= 1337;

        int ans = 1;

        for (int digit : b) {
            ans = power(ans, 10);
            ans = (ans * power(a, digit)) % 1337;
        }

        return ans;
    }
};