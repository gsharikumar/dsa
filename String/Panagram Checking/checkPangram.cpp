// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        // your code here
        int hash[256]={-1};
        int n=str.length();
        int i;
        for(i=0;i<26;i++){
            hash['a'+i]=0;
            hash['A'+i]=0;
        }
        for(i=0;i<n;i++){
            if(hash[str[i]]==0){
                hash[str[i]]++;
            }
        }
        for(i=0;i<26;i++){
            if(!(hash['a'+i]>0 || hash['A'+i]>0)){
                break;
            }
        }
        if(i==26){
            return true;
        }
        return false;
    }

};

// { Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}
  // } Driver Code Ends