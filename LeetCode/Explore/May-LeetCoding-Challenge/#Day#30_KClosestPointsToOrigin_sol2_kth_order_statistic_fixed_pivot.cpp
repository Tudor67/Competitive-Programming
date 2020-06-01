class Solution {
private:
    static int dist2(const vector<int>& p){
        return p[0] * p[0] + p[1] * p[1];
    }
    
    void nth_element(vector<vector<int>>& points, const int& K, const int& L, const int& R){
        vector<int> pivot = points[(L + R) / 2];
        int i = L, j = R;
        while(i < j){
            while(dist2(points[i]) < dist2(pivot)) ++i;
            while(dist2(pivot) < dist2(points[j])) --j;
            if(i <= j){
                swap(points[i], points[j]);
                ++i;
                --j;
            }
        }
        if(i <= K && i < R) nth_element(points, K, i, R);
        if(K <= j && L < j) nth_element(points, K, L, j);
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points, K - 1, 0, (int)points.size() - 1);
        vector<vector<int>> answer;
        for(int i = 0; i < K; ++i){
            answer.push_back(points[i]);
        }
        return answer;
    }
};