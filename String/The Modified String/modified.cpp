// { Driver Code Starts
#include<bits/stdc++.h>
#define br char xx; cin>>xx; cout<<xx<<endl;
#define lli long long int
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of characters which Ishaan must insert  
    //such that string doesn't have three consecutive same characters.
    int modified (string a)
    {
        // Your code here
        int n=a.length();
        int i;
        char nxt='a';
        if(n<=0){
            return 0;
        }
        for(i=0;i<n;i++){
            if(nxt<a[i]){
                nxt=a[i];
            }
        }
        nxt++;
        string b;
        int insCnt=0;
        int repeat=0;
        b.push_back(a[0]);
        for(i=1;i<n;i++){
            if(a[i-1]==a[i]){
                repeat++;
                if(repeat>1){
                    b.push_back(nxt);
                    repeat=0;
                    insCnt++;
                }
            }else{
                repeat=0;
            }
            b.push_back(a[i]);      
        }
       // cout<<b;
        return insCnt;
            
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        Solution obj;
        cout<<obj.modified(a)<<endl;
    }
    return 0;
}
  // } Driver Code Ends