class Solution {
public:
    bool isPalindrome(int x) {
        if((x<0 || x%10==0) && x!=0)
          return false;
        if(x==0)
            return true;
        long sum=0;
        while(x)
        {
            sum=sum*10+x%10;
            if(sum==x || x/10==sum)
            {
                return true;
            }
            x/=10;
        }
        return false;
    }
};