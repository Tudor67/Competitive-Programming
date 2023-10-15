class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        const int F = flowers.size();
        const int P = people.size();

        map<int, int> diff;
        for(const vector<int>& FLOWER: flowers){
            diff[FLOWER[0]] += 1;
            diff[FLOWER[1] + 1] -= 1;
        }

        vector<pair<int, int>> sortedPeopleIndex(P);
        for(int i = 0; i < P; ++i){
            sortedPeopleIndex[i] = {people[i], i};
        }

        sort(sortedPeopleIndex.begin(), sortedPeopleIndex.end());

        int fullBloomFlowers = 0;
        int pIndex = 0;

        vector<int> res(P);
        for(const pair<int, int>& D: diff){
            int t = D.first;
            while(pIndex < P && sortedPeopleIndex[pIndex].first < t){
                res[sortedPeopleIndex[pIndex].second] = fullBloomFlowers;
                pIndex += 1;
            }
            fullBloomFlowers += diff[t];
        }

        return res;
    }
};