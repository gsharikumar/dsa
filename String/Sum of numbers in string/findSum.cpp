// { Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	
    	// Your code here
    	int n=str.length();
    	string num;
    	int sum=0;
    	for(int i=0;i<n;i++){
    	    if(str[i]>='0' && str[i]<='9'){
    	       num.push_back(str[i]); 
    	    }else{
    	        if(num.length()>0){
    	            sum+=atoi(num.c_str());
    	            num.clear();
    	        }
    	    }
    	}
    	if(num.length()>0){
            sum+=atoi(num.c_str());
            num.clear();
    	}
    	return sum;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends