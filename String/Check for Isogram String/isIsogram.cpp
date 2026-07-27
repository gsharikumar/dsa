// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if a string is Isogram or not.
    bool isIsogram(string s)
    {
        //Your code here
        int n=s.length();
        int i;
        int hash[256]={0};
        for(i=0;i<n;i++){
            if(hash[s[i]]==0){
                hash[s[i]]++;
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

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.isIsogram(s)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends