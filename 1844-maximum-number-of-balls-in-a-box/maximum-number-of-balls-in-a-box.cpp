class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int balls[50]={};
        for(int i=lowLimit;i<=highLimit;i++){
            int sum=0,n=i;
            while(n){
                sum+=n%10;
                n=n/10; 
            }
            ++balls[sum];
        }
        return *max_element(begin(balls),end(balls));
    }
};