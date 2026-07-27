class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int size = arr.size();
        int i;
        int ret =-1;
        for(i = 0; i < size; i++)
        {
            if(x >= arr[i])
            {
                ret = i;
            }
        }
        return ret;
    }
};