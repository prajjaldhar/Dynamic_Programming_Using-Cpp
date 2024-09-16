class Solution {
public:
   int convertstringtoint(string str)
    {
        string s1 = str.substr(0,2);
        string s2= str.substr(3,2);
        int num1 = stoi(s1)*60;
        int num2= stoi(s2);
        return num1+num2;
    }

    int findMinDifference(vector<string>& s) 
    {
         sort(begin(s), end(s));
          s.push_back(s[0]);
          int ans = INT_MAX;
          for(int i=0;i<s.size()-1;i++)
          {
            int  time_one = convertstringtoint(s[i]);
             int time_two = convertstringtoint(s[i + 1]);
             // Calculate the difference between consecutive time points
             ans = min(ans, abs(time_one - time_two));  
             // Calculate the difference considering the circular nature of time
             ans = min(ans, abs(time_one - (1440 + time_two)));
          }
        return ans;
    }
};