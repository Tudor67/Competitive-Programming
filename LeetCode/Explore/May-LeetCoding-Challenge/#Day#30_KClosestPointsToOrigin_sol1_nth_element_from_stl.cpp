class Solution {
private:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return (a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]);
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(), comp);
        vector<vector<int>> answer;
        for(int i = 0; i < K; ++i){
            answer.push_back(points[i]);
        }
        return answer;
    }
};