class Solution {
public:
    int bulbSwitch(int n) {
        int i = 1;
        int ct = 0;

        while (i * i <= n) {
            i++;
            ct++;
        }

        return ct;
    }
};