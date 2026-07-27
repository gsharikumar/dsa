class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // code here
        int ret = -1;
        for(int i =0;i<arr.size();i++)
        {
            if(arr[i] == x)
            {
                ret = i;
                break;
            }
        }
        return ret;
    }
};