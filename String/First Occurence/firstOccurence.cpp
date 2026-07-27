// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     string ss=s,xx=x;
     int n=s.length();
     int m=x.length();
     int i=0;
     int j=0;
     
     if(n<m){
        // swap(n,m);
        // swap(ss,xx);
     }
     for(i=0;i<n-m+1;i++){
         for(j=0;j<m;j++){
             if(ss[i+j]!=xx[j]){
                 break;
             }
         }
         if(j==m)
         {
             return i;
         }
     }
     return -1;
}