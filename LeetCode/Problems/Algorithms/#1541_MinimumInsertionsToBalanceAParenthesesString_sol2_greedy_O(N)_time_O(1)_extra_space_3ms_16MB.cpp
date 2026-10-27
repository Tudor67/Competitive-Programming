class Solution {
public:
    int minInsertions(string s) {
        const int N = s.length();

        int minAddOps = 0;
        int currOpened = 0;
        int i = 0;
        while(i < N){
            if(s[i] == '('){
                currOpened += 1;
                i += 1;
            }else{
                if(i == N - 1 || s[i + 1] == '('){
                    minAddOps += 1;
                    i += 1;
                }else{
                    i += 2;
                }

                if(currOpened >= 1){
                    currOpened -= 1;
                }else{
                    minAddOps += 1;
                }
            }
        }

        minAddOps += (2 * currOpened);

        return minAddOps;
    }
};