class Solution {
public: 


    int digitcount(int n)
    {
        int count=0;
    while(n!=0)
    {
        count++;
        n/=10;
    }
    return count;
    }
    int sumofdigits(int n)
    {
        int sum=0;
        while(n!=0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int addDigits(int num) {
        if(num==0)
            return num;
        while(digitcount(num)!=1)
        {
            num=sumofdigits(num);
        }
        return num;
    }
};