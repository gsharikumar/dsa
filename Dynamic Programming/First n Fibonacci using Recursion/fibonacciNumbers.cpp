//User function template for C++


class Solution
{
public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n)
    {
        //code here
        vector<long long> fib(n, 0);

        if (n == 0) {
            return fib;
        }
        fib[0] = 1;
        if (n == 1) {
            return fib;
        }
        fib[1] = 1;
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        return fib;
    }
};