// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function Template for C++

class Solution
{
    public:
    //Function to find repeated character whose first appearance is leftmost.
    int repeatedCharacter (string s) 
    { 
        //Your code here
        int res=INT_MAX;
        int n=s.length();
        int i;
        int hash[256]={0};
        for(i=n-1;i>=0;i--){
            if(hash[s[i]] == 0){
                hash[s[i]]++;
            }else{
                res=min(res,i);
            }
        }
        if(res == INT_MAX){
            return -1;
        }else{
            return res;
        }
    } 
};

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    Solution obj;
	    int index = obj.repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
	}
	return 0;
}
  // } Driver Code Ends