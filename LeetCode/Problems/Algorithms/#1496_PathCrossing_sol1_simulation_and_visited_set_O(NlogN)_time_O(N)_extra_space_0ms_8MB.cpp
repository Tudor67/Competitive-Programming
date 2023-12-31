class Solution {
private:
    map<char, pair<int, int>> directionOf = {
        {'N', {0, 1}},
        {'S', {0, -1}},
        {'E', {1, 0}},
        {'W', {-1, 0}}
    };

public:
    bool isPathCrossing(string path) {
        const int N = path.size();

        pair<int, int> pos = {0, 0};
        set<pair<int, int>> visSet;
        visSet.insert(pos);

        for(char c: path){
            pos.first += directionOf[c].first;
            pos.second += directionOf[c].second;
            if(visSet.count(pos)){
                return true;
            }
            visSet.insert(pos);
        }

        return false;
    }
};