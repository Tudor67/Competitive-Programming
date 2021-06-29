class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        
        set<pair<int, int>> minSet;
        for(int i = 0; i < N; ++i){
            minSet.insert({ratings[i], i});
        }
        
        vector<int> candies(N, 1);
        for(const pair<int, int>& P: minSet){
            int idx = P.second;
            for(int neighIdx: {idx - 1, idx + 1}){
                if(0 <= neighIdx && neighIdx < N && ratings[idx] < ratings[neighIdx] && candies[idx] >= candies[neighIdx]){
                    candies[neighIdx] = 1 + candies[idx];
                }
            }
        }
        
        int totalCandies = 0;
        for(int i = 0; i < N; ++i){
            totalCandies += candies[i];
        }
        
        return totalCandies;
    }
};