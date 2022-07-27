class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        const int MAX_RATING = *max_element(ratings.begin(), ratings.end());
        
        // counter
        // count[x]: number of elements <= x in the original ratings vector
        vector<int> count(MAX_RATING + 1);
        for(int i = 0; i < N; ++i){
            count[ratings[i]] += 1;
        }
        
        for(int rating = 1; rating <= MAX_RATING; ++rating){
            count[rating] += count[rating - 1];
        }
        
        // p[i]: position of the (i + 1)th sorted rating in the original ratings vector
        vector<int> p(N);
        for(int i = 0; i < N; ++i){
            count[ratings[i]] -= 1;
            p[count[ratings[i]]] = i;
        }
        
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