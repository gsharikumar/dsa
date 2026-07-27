// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        // code here
        vector<int> roots;
        double img=b*b-4.0*a*c;
        if(img<0){
            roots.push_back(-1);
        }else{
            int r1=floor((-b + sqrt(img))/(2.0*a));
            int r2=floor((-b - sqrt(img))/(2.0*a));
            
            roots.push_back(r1<r2?r2:r1);
            roots.push_back(r1<r2?r1:r2);
        }
        return roots;
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends