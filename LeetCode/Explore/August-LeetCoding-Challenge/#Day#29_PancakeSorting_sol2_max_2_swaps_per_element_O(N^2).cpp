class Solution {
private:
    void pancake_flip(vector<int>& A, const int& K){
        reverse(A.begin(), A.begin() + K);
    }
    
public:
    vector<int> pancakeSort(vector<int>& A) {
        const int N = A.size();
        vector<int> answer;
        for(int i = N; i >= 1; --i){
            int pos = find(A.begin(), A.end(), i) - A.begin();
            if(pos + 1 != i){
                if(pos + 1 != 1){
                    answer.push_back(pos + 1);
                    pancake_flip(A, pos + 1);
                }
                answer.push_back(i);
                pancake_flip(A, i);
            }
        }
        return answer;
    }
};