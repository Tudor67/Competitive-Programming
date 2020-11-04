class Solution {
private:
    static bool comp(const pair<int, int>& LHS, const pair<int, int>& RHS){
        double l = (double)LHS.first / (double)LHS.second;
        double r = (double)RHS.first / (double)RHS.second;
        return (l < r);
    }
    
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        const int N = A.size();
        
        vector<pair<int, int>> fractions;
        fractions.reserve(N * (N - 1) / 2);
        for(int i = 0; i < N - 1; ++i){
            for(int j = i + 1; j < N; ++j){
                if(A[i] < A[j]){
                    fractions.push_back({A[i], A[j]});
                }
            }
        }
        
        nth_element(fractions.begin(), fractions.begin() + K - 1, fractions.end(), comp);
        
        return {fractions[K - 1].first, fractions[K - 1].second};
    }
};