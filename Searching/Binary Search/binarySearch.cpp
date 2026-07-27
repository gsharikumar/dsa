class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        // code here
        bool bFound = false;
        int m;
        int l = 0;
        int r = arr.size()-1;
        while(l<=r)
        {
            m = (r+l)/2;
            //cout << "l="<<l<<",m="<<m<<",r="<<r<<endl; 
            if(arr[m] == k)
            {
                bFound = true;
                break;
            }
            else if( arr[m] < k)
            {
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        return bFound;
    }
};