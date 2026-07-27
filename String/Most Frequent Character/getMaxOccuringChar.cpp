// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int n=str.length();
        int i;
        int hash[256]={0};
        int maxIdx=-1;
        int maxVal=INT_MIN;
        for(i=0;i<n;i++){
            hash[str[i]]++;
            if( maxVal<hash[str[i]] ){
                maxIdx=i;
                maxVal=hash[str[i]];
            }else if( maxVal == hash[str[i]]){
                if(str[i]<str[maxIdx]){
                    maxIdx=i;
                    maxVal=hash[str[i]];
                }
            }
        }
        if(maxIdx>-1){
            return str[maxIdx];
        }else{
            return '$';
        }
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends