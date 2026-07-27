// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
bool isPrime(int n) {
for(int i = 2; i*i <= n; i++) {
if(n%i == 0)
return false;
}
return true;
}
    int exactly3Divisors(int N)
    {
        //Your code here
        int i,j,k;
        int DCnt;
        int DCntTotal=0;

        if(N==1) return DCntTotal;
        if(N==2 || N==3) return DCntTotal;

        for(i=2;i*i<=N;i++){
            if(isPrime(i)){
                DCntTotal++;
            }
        }
        return DCntTotal;   
    }
};

// { Driver Code Starts.


int main()
 {
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling function exactly3Divisors()
        cout<<ob.exactly3Divisors(N)<<endl;
    }
	return 0;
}  // } Driver Code Ends