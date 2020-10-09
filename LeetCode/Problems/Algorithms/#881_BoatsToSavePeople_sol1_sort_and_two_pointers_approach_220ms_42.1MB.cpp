class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int answer = 0;
        int i = 0;
        int j = (int)people.size() - 1;
        while(i <= j){
            if(people[i] + people[j] <= limit){
                i += 1;
                j -= 1;
            }else{
                j -= 1;
            }
            answer += 1;
        }
        
        return answer;
    }
};