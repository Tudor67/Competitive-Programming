class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> answer(num_people, 0);
        
        int x = (-1 + sqrt(4LL * 2 * candies)) / 2;
        int rows = 1 + (x - 1) / num_people;
        int col = (x - 1) % num_people;
        
        for(int i = 0; i < num_people; ++i){
            if(i <= col){
                answer[i] = num_people * (rows - 1) * rows / 2 + (i + 1) * rows;
            }else{
                answer[i] = num_people * (rows - 2) * (rows - 1) / 2 + (i + 1) * (rows - 1);
            }
        }
        
        answer[(col + 1) % num_people] += (candies - x * (x + 1) / 2);
        
        return answer;
    }
};