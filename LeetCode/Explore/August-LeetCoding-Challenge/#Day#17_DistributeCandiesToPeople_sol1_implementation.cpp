class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> answer(num_people, 0);
        int idx = 0;
        while(candies >= 0){
            answer[idx % num_people] += min(idx + 1, candies);
            candies -= (idx + 1);
            idx += 1;
        }
        return answer;
    }
};