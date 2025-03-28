class Solution {
private:
    bool checkValidCuts(vector<pair<int, int>>& segments){
        vector<pair<int, int>> events;
        events.reserve(2 * segments.size());
        for(auto& [l, r]: segments){
            events.push_back({l, 1});
            events.push_back({r + 1, -1});
        }

        sort(events.begin(), events.end());

        int validCutsCount = 0;
        int activeSegments = 0;
        int maxPos = events.back().first;

        for(auto& [currPos, currDelta]: events){
            activeSegments += currDelta;
            if(activeSegments == 0 && currPos != maxPos){
                validCutsCount += 1;
            }
        }

        return (validCutsCount >= 2);
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        const int R = rectangles.size();

        vector<pair<int, int>> hSegments(R);
        vector<pair<int, int>> vSegments(R);

        for(int i = 0; i < R; ++i){
            int x1 = rectangles[i][0];
            int y1 = rectangles[i][1];
            int x2 = rectangles[i][2];
            int y2 = rectangles[i][3];
            hSegments[i] = {x1, x2 - 1};
            vSegments[i] = {y1, y2 - 1};
        }

        return (checkValidCuts(hSegments) ||
                checkValidCuts(vSegments));
    }
};