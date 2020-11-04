class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        const int N = A.size();
        
        vector<tuple<double, int, int>> fractions;
        fractions.reserve(N * (N - 1) / 2);
        for(int i = 0; i < N - 1; ++i){
            for(int j = i + 1; j < N; ++j){
                if(A[i] < A[j]){
                    fractions.push_back({(double)A[i] / (double)A[j], A[i], A[j]});
                }
            }
        }
        
        nth_element(fractions.begin(), fractions.begin() + K - 1, fractions.end());
        
        return {get<1>(fractions[K - 1]), get<2>(fractions[K - 1])};
    }
};