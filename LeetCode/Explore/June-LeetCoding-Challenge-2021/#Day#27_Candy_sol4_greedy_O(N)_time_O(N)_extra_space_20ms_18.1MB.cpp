class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        
        vector<int> incLRLen(N, 1);
        for(int i = 1; i < N; ++i){
            if(ratings[i - 1] < ratings[i]){
                incLRLen[i] = 1 + incLRLen[i - 1];
            }
        }
        
        vector<int> incRLLen(N, 1);
        for(int i = N - 2; i >= 0; --i){
            if(ratings[i] > ratings[i + 1]){
                incRLLen[i] = 1 + incRLLen[i + 1];
            }
        }
        
        int totalCandies = 0;
        for(int i = 0; i < N; ++i){
            totalCandies += max(incLRLen[i], incRLLen[i]);
        }
        
        return totalCandies;
    }
};

/*
ratings:  1 2 5 9 7 6 5 4 3 2 1
incLRLen: 1 2 3 4 1 1 1 1 1 1 1
incRLLen: 1 1 1 8 7 6 5 4 3 2 1
candies:  1 2 3 8 7 6 5 4 3 2 1

ratings:  1 2 5 9 7 6 6 5 4 3 2 1
incLRLen: 1 2 3 4 1 1 1 1 1 1 1 1
incRLLen: 1 1 1 3 2 1 6 5 4 3 2 1
candies:  1 2 3 4 2 1 6 5 4 3 2 1
*/