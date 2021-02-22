class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        const int N = A.size();
        int answer = 0;
        int i = 0;
        while(i + 2 < N){
            int startPos = i;
            int diff = A[i + 1] - A[i];
            while(i + 2 < N && A[i + 2] - A[i + 1] == diff){
                answer += (i - startPos + 1);
                i += 1;
            }
            if(i == startPos){
                i += 1;
            }
        }
        return answer;
    }
};