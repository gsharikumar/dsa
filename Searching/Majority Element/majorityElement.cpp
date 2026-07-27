class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int size = arr.size();
        int cnt = 0;
        int el;
        for(int i = 0;i < size; i++)
        {
            if(cnt == 0)
            {
                el = arr[i];
                cnt = 1;
            }
            else if(arr[i] == el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        cnt = 0;
        for(int i = 0;i < size; i++)
        {
            if(arr[i] == el)
            {
                cnt++;
                if(cnt > (size/2))
                {
                    return el;
                    break;
                }
            }
        }
        return -1;
    }
};