class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int ans = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {

            empty -= numExchange;   // exchange empties

            ans++;                  // drink new bottle

            empty++;                // new empty bottle

            numExchange++;          // next exchange costs more
        }

        return ans;
    }
};