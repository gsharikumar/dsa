//User function Template for C++

class Solution
{
    public:
    //Function to print the maximum contiguous subarray sum ending at each 
    //position in the array and return the overall maximum.
    long long maximumSum(int arr[], int sizeOfArray)
    {
       //code here
       long long localMax[sizeOfArray];
       long long globalMax;
       globalMax=localMax[0]=arr[0];
       cout<<localMax[0];
       for(int i=1;i<sizeOfArray;i++){
            cout<<" ";
            if(arr[i] < (arr[i]+localMax[i-1])){
                localMax[i]=(arr[i]+localMax[i-1]);
            }else{
                localMax[i]=arr[i];
            }
            cout<<localMax[i];
            globalMax=max(globalMax,localMax[i]);
       }
       cout<<endl;
       return globalMax;
    }
};