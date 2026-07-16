class Solution {
public:
    int findNthDigit(int n) {
        int digits = 1;
        int count = 9;
        int start = 1;

        while (n/digits > count) {
            n -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }

        int number = start + (n - 1) / digits;
        string s = to_string(number);

        return s[(n - 1) % digits] - '0';
    }
};