class Solution {
  public:
    // You need to complete this function
    int c=0;
    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int from, int to, int aux) {
        // Your code here
        if(n==0)
        return 0;
        toh(n-1,from,aux,to);
        c++;
        cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        toh(n-1,aux,to,from);
        return c;
    }
};