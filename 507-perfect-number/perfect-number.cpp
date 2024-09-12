class Solution {
public:
    bool checkPerfectNumber(int num) {
        int s = 0, i = 1;
        while (i * i < num) {
            if (num % i == 0) {
                s += i;
                if (i != 1 && i != num / i) {
                    s += num / i;
                }
            }
            i++;
        }
        return num == s;
    }
};