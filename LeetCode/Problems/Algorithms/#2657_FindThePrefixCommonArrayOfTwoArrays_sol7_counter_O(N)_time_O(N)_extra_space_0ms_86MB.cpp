class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int N = A.size();

        vector<int> res(N);
        vector<int> count(N + 1);
        int prefixIntersection = 0;

        for(int i = 0; i < N; ++i){
            count[A[i]] += 1;
            if(count[A[i]] == 2){
                prefixIntersection += 1;
            }

            count[B[i]] += 1;
            if(count[B[i]] == 2){
                prefixIntersection += 1;
            }

            res[i] = prefixIntersection;
        }

        return res;
    }
};