
class Solution
{
public:
    //Function to find sum of all possible substrings of the given string.

    long long sumSubstringsNaive(string s) {
        // your code here
        int len = s.length();
        long long sum = 0;
        for (int i = 0; i < len; i++) {
            string subStr;
            for (int j = i; j < len; j++) {
                subStr += s[j];
                if (false == subStr.empty()) {
                    sum = sum + (long long)(stoi(subStr));
                    sum = sum % (1000000007);
                    //cout <<subStr<<"("<<stoi(subStr)<<","<<sum<<")"<<" ";
                }
            }
        }
        return sum;
    }


    long long sumSubstringsOpt(string s) {
        // your code here
        int len = s.length();
        long long sum = 0;
        long long dp[len];

        for (int i = 0; i < len; i++) {
            string subStr;
            dp[i] = s[i] - '0';
            sum = (sum + dp[i]) % (1000000007);
            for (int j = i + 1; j < len; j++) {
                dp[j] = ((dp[j - 1] * 10) + (s[j] - '0')) % (1000000007);
                sum = (sum + dp[j]) % (1000000007);
                //subStr+=s[j];
                //if(false == subStr.empty()){
                //    sum=sum + (long long)(stoi(subStr));
                //    sum=sum%(1000000007);
                    //cout <<subStr<<"("<<stoi(subStr)<<","<<sum<<")"<<" ";
                //}
            }
        }
        return sum;
    }


    long long sumSubstrings(string s) {
        // your code here

        return sumSubstringsOpt(s);
        return sumSubstringsNaive(s);
    }

    //!!!!!!! XXXX caution watchout for the below mistake, misunderstanding of substring/subarray vs subsequence XXXX
    long long sumSubSequencestringsRecur(string s, int len, string ss) {
        //this is generating sub sequence XXXXX, but substring is contiguous
        if (len == 0) {

            cout << ss << " ";
            if (ss.empty() == false) {
                return stoi(ss) % (10 ^ 9 + 7);
            }
            else {
                return 0;
            }
        }
        string includeSS = ss;
        includeSS.push_back(s[len - 1]);
        return sumSubSequencestringsRecur(s, len - 1, ss) + sumSubSequencestringsRecur(s, len - 1, includeSS);
    }
};