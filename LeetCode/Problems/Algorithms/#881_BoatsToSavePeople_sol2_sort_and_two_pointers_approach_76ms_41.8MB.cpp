class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int answer = 0;
        sort(people.begin(), people.end());
        for(int i = 0, j = (int)people.size() - 1; i <= j; --j){
            if(people[i] + people[j] <= limit){
                i += 1;
            }
            answer += 1;
        }
        return answer;
    }
};