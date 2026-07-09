class Solution {
public:
    int arrangeCoins(int n) {
              int rows = 0;

        for (int i = 1; n >= i; i++) {
            n -= i;
            rows++;
        }

        return rows;
    }
};