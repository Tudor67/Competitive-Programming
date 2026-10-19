class Solution {
public:
    bool sumGame(string s) {
        const int N = s.length();

        int leftSum = 0;
        int leftQ = 0;
        int rightSum = 0;
        int rightQ = 0;

        for(int i = 0; i < N / 2; ++i){
            if(isdigit(s[i])){
                leftSum += (s[i] - '0');
            }else{
                leftQ += 1;
            }

            if(isdigit(s[i + N / 2])){
                rightSum += (s[i + N / 2] - '0');
            }else{
                rightQ += 1;
            }
        }
        
        int sumDiff = leftSum - rightSum;
        int qDiff = leftQ - rightQ;
        return (qDiff % 2 != 0 || -qDiff * 9 / 2 != sumDiff);
    }
};