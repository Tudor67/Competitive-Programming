class Solution {
public:
    int longestMountain(vector<int>& A) {
        const int N = A.size();
        int answer = 0;
        
        int i = 0;
        while(i < N){
            int j = i + 1;
            // increasing subarray
            int incCnt = (i > 0 && A[i - 1] < A[i] ? 2 : 1);
            while(j < N && A[j - 1] < A[j]){
                j += 1;
                incCnt += 1;
            }
            // decreasing subarray
            int decCnt = 1;
            while(j < N && A[j - 1] > A[j]){
                j += 1;
                decCnt += 1;
            }
            // update answer
            if(incCnt >= 2 && decCnt >= 2 && incCnt + decCnt - 1 > answer){
                answer = incCnt + decCnt - 1;
            }
            // update i
            if(j < N && A[j - 1] < A[j]){
                i = j - 1;
            }else{
                i = j;
            }
        }
        
        return answer;
    }
};