class Solution {
private:
    unordered_map<char, pair<int, int>> directionOf = {
        {'N', {0, 1}},
        {'S', {0, -1}},
        {'E', {1, 0}},
        {'W', {-1, 0}}
    };

    int pairToCode(const pair<int, int>& P, const int& BASE){
        return P.first * BASE + P.second;
    }

public:
    bool isPathCrossing(string path) {
        const int N = path.size();
        const int BASE = 1e4 + 7;

        pair<int, int> pos = {0, 0};
        unordered_set<int> visSet;
        visSet.insert(pairToCode(pos, BASE));

        for(char c: path){
            pos.first += directionOf[c].first;
            pos.second += directionOf[c].second;
            int posCode = pairToCode(pos, BASE);
            if(visSet.count(posCode)){
                return true;
            }
            visSet.insert(posCode);
        }

        return false;
    }
};