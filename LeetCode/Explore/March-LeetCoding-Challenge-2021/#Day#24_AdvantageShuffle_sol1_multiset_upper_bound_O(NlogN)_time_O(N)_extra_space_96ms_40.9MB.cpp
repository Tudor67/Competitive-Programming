class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        vector<int> answer(N);
        multiset<int> valuesA(A.begin(), A.end());
        for(int i = 0; i < N; ++i){
            multiset<int>::iterator it = valuesA.upper_bound(B[i]);
            if(it == valuesA.end()){
                answer[i] = *valuesA.begin();
                valuesA.erase(valuesA.begin());
            }else{
                answer[i] = *it;
                valuesA.erase(it);
            }
        }
        return answer;
    }
};