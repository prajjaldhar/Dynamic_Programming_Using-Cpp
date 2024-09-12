class Solution {
public:
     int selfDivide(int n) {
        int x = n; 
        while(n > 0) {
            if(n % 10 == 0) {
                return -1; 
            } else {
                if(x % (n % 10) == 0) {
                    n /= 10; 
                } else {
                    return -1; 
                }
            }
        }
        return 1; 
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> m; 
        for(int i = left; i <= right; ++i) {
            if(selfDivide(i) == 1) {
                m.push_back(i); 
            }
        }
        return m; 
    }
};