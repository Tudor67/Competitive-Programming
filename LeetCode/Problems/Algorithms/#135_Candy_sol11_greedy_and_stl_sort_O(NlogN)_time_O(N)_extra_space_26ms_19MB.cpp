class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return (ratings[lhs] < ratings[rhs]);
             });

        vector<int> candies(N, 1);
        for(int i: p){
            if(i - 1 >= 0 && ratings[i] > ratings[i - 1]){
                candies[i] = max(candies[i], candies[i - 1] + 1);
            }
            if(i + 1 < N && ratings[i] > ratings[i + 1]){
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};