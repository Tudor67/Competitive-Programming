class Solution {
private:
    void minimize(unordered_map<int, int>& mp, int key, int newVal){
        if(mp.count(key)){
            mp[key] = min(mp[key], newVal);
        }else{
            mp[key] = newVal;
        }
    }

    void maximize(unordered_map<int, int>& mp, int key, int newVal){
        if(mp.count(key)){
            mp[key] = max(mp[key], newVal);
        }else{
            mp[key] = newVal;
        }
    }

public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, int> xToMinY;
        unordered_map<int, int> xToMaxY;
        unordered_map<int, int> yToMinX;
        unordered_map<int, int> yToMaxX;
        for(vector<int>& building: buildings){
            int x = building[0];
            int y = building[1];
            minimize(xToMinY, x, y);
            maximize(xToMaxY, x, y);
            minimize(yToMinX, y, x);
            maximize(yToMaxX, y, x);
        }

        int coveredBuildings = 0;
        for(vector<int>& building: buildings){
            int x = building[0];
            int y = building[1];
            if(xToMinY[x] < y && y < xToMaxY[x] &&
               yToMinX[y] < x && x < yToMaxX[y]){
                coveredBuildings += 1;
            }
        }

        return coveredBuildings;
    }
};