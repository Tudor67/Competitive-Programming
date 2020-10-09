class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> answer;
        for(int i = 0, j = (int)A.size() - 1; i <= j;){
            if(A[i] * A[i] > A[j] * A[j]){
                answer.push_back(A[i] * A[i]);
                i += 1;
            }else{
                answer.push_back(A[j] * A[j]);
                j -= 1;
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};