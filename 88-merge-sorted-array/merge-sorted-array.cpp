class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        int i=m-1,j=n-1,k=num1.size()-1;
        while(i>=0 && j>=0)
        {
            if(num1[i]>num2[j])
            {
                num1[k]=num1[i];
                i--;
            }
            else
            {
               num1[k]=num2[j];
                j--;  
            }
            k--;
        }
          // Copy remaining elements of nums2
        while (j >= 0) {
            num1[k] = num2[j];
            j--;
            k--;
        }
        
    }
};