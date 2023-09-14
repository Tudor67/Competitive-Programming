class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        const int MAX_RATING = *max_element(ratings.begin(), ratings.end());

        vector<int> prefCount(MAX_RATING + 1);
        for(int rating: ratings){
            prefCount[rating] += 1;
        }

        for(int rating = 1; rating <= MAX_RATING; ++rating){
            prefCount[rating] += prefCount[rating - 1];
        }

        vector<int> p(N);
        for(int i = N - 1; i >= 0; --i){
            prefCount[ratings[i]] -= 1;
            p[prefCount[ratings[i]]] = i;
        }
        
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