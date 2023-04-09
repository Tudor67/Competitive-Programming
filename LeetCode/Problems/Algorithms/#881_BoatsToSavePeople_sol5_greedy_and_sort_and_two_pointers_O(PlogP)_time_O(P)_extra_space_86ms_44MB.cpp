class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        const int P = people.size();

        vector<int> sortedPeople = people;
        sort(sortedPeople.begin(), sortedPeople.end());

        int totalBoats = 0;
        int l = 0;
        for(int r = P - 1; r >= l; --r){
            if(r > l && sortedPeople[l] + sortedPeople[r] <= limit){
                l += 1;
            }
            totalBoats += 1;
        }

        return totalBoats;
    }
};