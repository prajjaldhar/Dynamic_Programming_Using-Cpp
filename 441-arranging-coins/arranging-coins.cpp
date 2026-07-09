class Solution {
public:
    int arrangeCoins(int n) {
          long long low = 1;
          long long high = n;
          long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long coinsNeeded = mid * (mid + 1) / 2;

            if (coinsNeeded <= n) {
                ans = mid;       // mid rows possible hain
                low = mid + 1;   // aur zyada rows try karo
            } else {
                high = mid - 1;  // coins kam hain
            }
        }

        return ans;
    }
};