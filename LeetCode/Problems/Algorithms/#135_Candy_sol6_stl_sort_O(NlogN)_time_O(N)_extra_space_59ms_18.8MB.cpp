class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        
        vector<pair<int, int>> sortedRatingIndex(N);
        for(int i = 0; i < N; ++i){
            sortedRatingIndex[i] = {ratings[i], i};
        }
        
        sort(sortedRatingIndex.begin(), sortedRatingIndex.end());
        
        vector<int> candies(N, 1);
        for(int i = 0; i < N; ++i){
            int idx = sortedRatingIndex[i].second;
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