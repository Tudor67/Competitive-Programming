class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        const int M = matches.size();

        map<int, int> lossCount;
        for(const vector<int>& MATCH: matches){
            int a = MATCH[0];
            int b = MATCH[1];
            lossCount.insert({a, 0});
            lossCount[b] += 1;
        }

        vector<vector<int>> answer(2);
        for(const pair<const int, int>& P: lossCount){
            int a = P.first;
            int aLossCount = P.second;
            if(aLossCount <= 1){
                answer[aLossCount].push_back(a);
            }
        }

        return answer;
    }
};