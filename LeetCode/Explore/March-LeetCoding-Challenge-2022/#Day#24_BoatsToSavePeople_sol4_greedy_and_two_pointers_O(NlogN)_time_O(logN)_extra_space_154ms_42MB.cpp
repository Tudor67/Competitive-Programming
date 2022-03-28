class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        const int N = people.size();
        
        sort(people.begin(), people.end());
        
        int boats = 0;
        int i = 0;
        int j = N - 1;
        while(i <= j){
            if(people[i] + people[j] <= limit){
                ++i;
            }
            --j;
            ++boats;
        }
        
        return boats;
    }
};