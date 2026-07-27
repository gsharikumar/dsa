// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int i;
        int n=str1.length();
        int m=str2.length();
        if(n!=m){
            return false;
        }
        for(i=0;i<n;i++){
            if(str1[i]==str2[(i+2)%n]){
                
            }else if(str1[i]==str2[(n+i-2)%n]){
                
            }else{
                break;
            }
        }
        if(i==n){
            return true;
        }
        return false;
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends