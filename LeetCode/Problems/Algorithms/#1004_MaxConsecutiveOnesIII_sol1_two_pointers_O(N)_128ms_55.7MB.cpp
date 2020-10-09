class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int answer = 0;
        int replacements = 0;
        for(int i = 0, j = 0; j < A.size(); ++j){
            replacements += (A[j] == 0);
            while(replacements > K){
                replacements -= (A[i] == 0);
                i += 1;
            }
            answer = max(j - i + 1, answer);
        }
        return answer;
    }
};