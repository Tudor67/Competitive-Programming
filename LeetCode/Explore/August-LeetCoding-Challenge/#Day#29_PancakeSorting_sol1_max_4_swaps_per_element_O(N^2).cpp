class Solution {
private:
    void pancake_flip(vector<int>& A, const int& K){
        reverse(A.begin(), A.begin() + K);
    }
    
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> answer;
        for(int i = 1; i < A.size(); ++i){
            if(A[i - 1] > A[i]){
                int pos = upper_bound(A.begin(), A.begin() + i, A[i]) - A.begin() - 1;
                for(int k: {i + 1, i - pos, i - pos - 1, i + 1}){
                    if(k != 1){
                        answer.push_back(k);
                        pancake_flip(A, k);
                    }
                }
            }
        }
        return answer;
    }
};