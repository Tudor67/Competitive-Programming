class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        const int N = people.size();

        vector<int> sortedPeople = people;
        sort(sortedPeople.begin(), sortedPeople.end());

        int l = 0;
        int r = N - 1;
        int boats = 0;

        while(l <= r){
            boats += 1;
            if(sortedPeople[l] + sortedPeople[r] <= limit){
                l += 1;
                r -= 1;
            }else{
                r -= 1;
            }
        }

        return boats;
    }
};