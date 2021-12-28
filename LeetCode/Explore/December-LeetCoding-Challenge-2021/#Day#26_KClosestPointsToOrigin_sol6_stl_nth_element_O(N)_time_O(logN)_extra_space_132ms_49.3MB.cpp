class Solution {
private:
    static bool incDistComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[0] * LHS[0] + LHS[1] * LHS[1]) < (RHS[0] * RHS[0] + RHS[1] * RHS[1]);
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k - 1, points.end(), incDistComp);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};