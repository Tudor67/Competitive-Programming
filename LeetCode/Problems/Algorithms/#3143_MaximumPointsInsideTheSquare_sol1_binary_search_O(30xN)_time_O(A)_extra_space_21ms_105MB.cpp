class Solution {
private:
    int countTags(vector<vector<int>>& points, string& s, int sideLen){
        const int N = s.length();

        unordered_set<char> vis;
        for(int i = 0; i < N; ++i){
            if(max(abs(points[i][0]), abs(points[i][1])) > sideLen){
                // point outside the square
            }else if(vis.count(s[i])){
                return -1;
            }else{
                vis.insert(s[i]);
            }
        }

        return vis.size();
    }

public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int l = 0;
        int r = 1'000'000'000;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(countTags(points, s, mid) < 0){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        return countTags(points, s, r);
    }
};