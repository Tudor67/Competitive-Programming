class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        const int N = min({s1.length(), s2.length(), s3.length()});

        int i = 0;
        while(i < N && s1[i] == s2[i] && s2[i] == s3[i]){
            i += 1;
        }

        if(i == 0){
            return -1;
        }

        return (int)(s1.length() + s2.length() + s3.length()) - 3 * i;
    }
};