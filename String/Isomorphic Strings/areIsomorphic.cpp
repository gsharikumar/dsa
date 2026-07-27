// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int n=str1.length();
        int m=str2.length();
        char hash1[256]={0};
        char hash2[256]={0};
        int i;
        
        if(n!=m){
            return false;
        }
        
        for(i=0;i<n;i++){
            if(hash1[str1.at(i)]==0){
                hash1[str1[i]]=str2[i];
            }
            if(hash2[str2.at(i)]==0){
                hash2[str2[i]]=str1[i];
            }
            if(!(hash1[str1[i]]==str2[i] && hash2[str2[i]]==str1[i] )){
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

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends