class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        
        vector<int> candies(N, 1);
        for(int isReversed = 1; isReversed >= 0; --isReversed){
            reverse(ratings.begin(), ratings.end());
            reverse(candies.begin(), candies.end());
            for(int i = 1; i < N; ++i){
                if(ratings[i - 1] < ratings[i]){
                    candies[i] = max(1 + candies[i - 1], candies[i]);
                }
            }
        }
        
        int totalCandies = accumulate(candies.begin(), candies.end(), 0);
        
        return totalCandies;
    }
};

/*
ratings: 1 2 5 9 7 6 5 4 3 2 1 
candies: 1 2 3 8 7 6 5 4 3 2 1 

ratings: 1 2 5 9 7 6 6 5 4 3 2 1
candies: 1 2 3 4 2 1 6 5 4 3 2 1
*/