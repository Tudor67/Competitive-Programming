class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        const int MAX_POS = max(x, *max_element(forbidden.begin(), forbidden.end())) + a + b;
        const int INF = 1e9;

        vector<bool> isValid(MAX_POS + 1, true);
        for(int forbiddenPos: forbidden){
            isValid[forbiddenPos] = false;
        }

        vector<int> minJumps(MAX_POS + 1, INF);
        set<pair<int, int>> statesSet;
        minJumps[0] = 0;
        statesSet.insert({minJumps[0], 0});

        while(!statesSet.empty()){
            int pos = statesSet.begin()->second;
            statesSet.erase(statesSet.begin());

            if(pos == x){
                return minJumps[x];
            }

            for(const pair<int, int> P: vector<pair<int, int>>{{1, pos + a}, {2, pos + a - b}}){
                int cost = P.first;
                int nextPos = P.second;
                if(0 <= pos + a && pos + a <= MAX_POS && 0 <= nextPos && nextPos <= MAX_POS){
                    if(isValid[pos + a] && isValid[nextPos] && minJumps[pos] + cost < minJumps[nextPos]){
                        statesSet.erase({minJumps[nextPos], nextPos});
                        minJumps[nextPos] = minJumps[pos] + cost;
                        statesSet.insert({minJumps[nextPos], nextPos});
                    }
                }
            }
        }

        return -1;
    }
};