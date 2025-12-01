class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
          sort(batteries.begin(),batteries.end());
          long long total=accumulate(batteries.begin(),batteries.end(), 0LL);

          for(int i=batteries.size()-1; i>=0;i--)
          {
            if(batteries[i]<=total/n)
            break;

            total-=batteries[i];
            n--;
          }

     return total/n;
    }
};