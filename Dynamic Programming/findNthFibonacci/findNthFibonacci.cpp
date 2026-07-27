//User function Template for C++
// You need to complete this function


class Solution
{
    public:
    //Function to find the nth fibonacci number using bottom-up approach.
    long long findNthFibonacci(int number)
    {
        // Your Code Here
        int i;
        long long fib[number+1];
        fib[0] = 0;
        fib[1] = 1;
        
        for(i = 2; i <= number;i++){
            fib[i] = fib[i-1] + fib[i-2];
        }

        return fib[number];
    }
    
    long long findNthFibonacciNaive(int number)
    {
        // Your Code Here
        int i;
        if(number <= 0 ){
            return 0;
        }
        if(number == 1){
            return number;
        }
        long long fib;
        fib = findNthFibonacci(number-1) + findNthFibonacci(number-2);
        
        return fib;
    }
};