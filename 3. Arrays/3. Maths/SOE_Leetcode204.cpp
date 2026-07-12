class Solution {
public:

    // SIEVE OF ERATOSTHENES

    int countPrimes(int n) {
        vector<bool> mark(n,true);
        for(int i=2;i*i<n;i++) {
            if(mark[i])
            {
                for(int j=i*i;j<n;j+=i) {
                    mark[j]=false;
                }
            }
        }
        int c=0;
        for(int i=2;i<n;i++) {
            if(mark[i])
            c++;
        }
        return c;
    }
};