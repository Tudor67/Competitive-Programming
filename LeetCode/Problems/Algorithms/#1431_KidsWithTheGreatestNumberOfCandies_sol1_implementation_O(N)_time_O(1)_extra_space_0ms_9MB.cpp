class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        const int N = candies.size();
        const int MAX_CANDIES = *max_element(candies.begin(), candies.end());

        vector<bool> answer(N, false);
        for(int i = 0; i < N; ++i){
            if(candies[i] + extraCandies >= MAX_CANDIES){
                answer[i] = true;
            }
        }

        return answer;
    }
};