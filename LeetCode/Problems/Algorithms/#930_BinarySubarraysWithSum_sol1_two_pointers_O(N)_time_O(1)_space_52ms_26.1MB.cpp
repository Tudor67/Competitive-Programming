class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        const int N = A.size();
        int answer = 0;
        int sum = 0;
        for(int i = 0, j = 0; j < N; ++j){
            sum += A[j];
            while(sum > S){
                sum -= A[i];
                i += 1;
            }
            if(i <= j && sum == S){
                int nextI = i;
                int nextJ = j + 1;
                while(nextJ < N && A[nextJ] == 0) nextJ += 1;
                while(nextI < N && A[nextI] == 0) nextI += 1;
                if(S == 0){
                    answer += (nextJ - i) * (nextJ - i + 1) / 2;
                }else{
                    answer += (nextI - i + 1) * (nextJ - j);
                }
                i = nextI;
                j = nextJ - 1;
            }
        }
        return answer;
    }
};