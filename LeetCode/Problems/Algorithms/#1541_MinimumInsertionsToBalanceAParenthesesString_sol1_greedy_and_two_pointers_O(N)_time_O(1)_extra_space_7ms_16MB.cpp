class Solution {
public:
    int minInsertions(string s) {
        const int N = s.length();

        int minAddOps = 0;
        int currOpened = 0;
        int i = 0;
        while(i < N){
            int j = i;
            while(j < N && s[i] == s[j]){
                j += 1;
            }

            int currLen = j - i;
            if(s[i] == '('){
                currOpened += currLen;
            }else{
                if(currLen % 2 == 1){
                    currLen += 1;
                    minAddOps += 1;
                }

                int validClosed = min(2 * currOpened, currLen);
                currOpened -= validClosed / 2;
                currLen -= validClosed;
                minAddOps += currLen / 2;
            }

            i = j;
        }

        minAddOps += (2 * currOpened);

        return minAddOps;
    }
};