class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        
        vector<int> sortedA = A;
        vector<pair<int, int>> B2(N);
        for(int i = 0; i < N; ++i){
            B2[i] = {B[i], i};
        }
        
        sort(sortedA.begin(), sortedA.end());
        sort(B2.begin(), B2.end());
        
        vector<int> answer(N);
        int i1 = 0;
        int i2 = N - 1;
        for(int j = N - 1; j >= 0; --j){
            if(sortedA[i2] > B2[j].first){
                answer[B2[j].second] = sortedA[i2];
                i2 -= 1;
            }else{
                answer[B2[j].second] = sortedA[i1];
                i1 += 1;
            }
        }
        
        return answer;
    }
};