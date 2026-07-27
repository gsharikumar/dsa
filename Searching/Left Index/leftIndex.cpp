class Solution {
  public:
    int leftIndex(vector<int>& arr, int x) {
        // code here
        int size = arr.size();
        int low = 0;
        int high = size;
        int mid;
        int res = -1;
        while(low <= high)
        {
            mid = (high + low)/2;
            if(arr[mid] < x)
            {
                low = mid+1;
            }
            else if(arr[mid] > x)
            {
                high = mid -1;
            }
            else
            {
                res = mid;
                break;
            }
        }
        for(int i = res;i>=0;i--)
        {
            if(arr[i] != x)
            {
                break;
            }
            else
            {
                res = i;
            }
        }
        return res;
    }
};