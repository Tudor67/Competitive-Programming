class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        const int N = points.size();

        map<int, string> tagsAt;
        for(int i = 0; i < N; ++i){
            tagsAt[max(abs(points[i][0]), abs(points[i][1]))].push_back(s[i]);
        }

        unordered_set<char> vis;
        for(auto [dist, tags]: tagsAt){
            int prevVisSize = vis.size();
            for(char tag: tags){
                if(vis.count(tag)){
                    return prevVisSize;
                }
                vis.insert(tag);
            }
        }

        return vis.size();
    }
};