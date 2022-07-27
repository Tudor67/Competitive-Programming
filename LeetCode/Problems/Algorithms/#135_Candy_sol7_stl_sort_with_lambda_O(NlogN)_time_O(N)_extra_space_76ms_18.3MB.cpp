class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](const int& LHS, const int& RHS){
                 return (ratings[LHS] < ratings[RHS]);
             });
        
        vector<int> candies(N, 1);
        for(int i = 0; i < N; ++i){
            int idx = p[i];
            if(idx - 1 >= 0 && ratings[idx - 1] > ratings[idx]){
                candies[idx - 1] = max(candies[idx - 1], candies[idx] + 1);
            }
            if(idx + 1 < N && ratings[idx] < ratings[idx + 1]){
                candies[idx + 1] = max(candies[idx + 1], candies[idx] + 1);
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};