// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
    	unsigned int nc=n;
    	unsigned int mask=3;
    	unsigned int i=1;
    	unsigned int toApply;
    	unsigned int swapped=0;
    	while(nc){
    	     mask=(((nc>>1) & 1)  | ( (nc<<1) & 2)) ;
    	     swapped=swapped | (mask*i);
    	    i=i<<2;
    	    nc=nc>>2; 
    	}
    	return swapped;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}  // } Driver Code Ends