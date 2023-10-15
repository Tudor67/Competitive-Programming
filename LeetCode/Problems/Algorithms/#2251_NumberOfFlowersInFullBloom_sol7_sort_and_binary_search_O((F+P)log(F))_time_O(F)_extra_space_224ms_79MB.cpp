class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        const int F = flowers.size();
        const int P = people.size();

        vector<int> sortedStartTimes(F);
        vector<int> sortedEndTimes(F);
        for(int i = 0; i < F; ++i){
            sortedStartTimes[i] = flowers[i][0];
            sortedEndTimes[i] = flowers[i][1];
        }

        sort(sortedStartTimes.begin(), sortedStartTimes.end());
        sort(sortedEndTimes.begin(), sortedEndTimes.end());

        vector<int> res(P);
        for(int i = 0; i < P; ++i){
            int t = people[i];
            int startCount = upper_bound(sortedStartTimes.begin(), sortedStartTimes.end(), t) - sortedStartTimes.begin();
            int endCount = lower_bound(sortedEndTimes.begin(), sortedEndTimes.end(), t) - sortedEndTimes.begin();
            res[i] = startCount - endCount;
        }

        return res;
    }
};