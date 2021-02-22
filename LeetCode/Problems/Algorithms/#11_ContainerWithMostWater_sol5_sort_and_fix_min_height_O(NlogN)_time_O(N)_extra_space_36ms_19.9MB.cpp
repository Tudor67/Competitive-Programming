class Solution {
public:
    int maxArea(vector<int>& heights) {
        const int N = heights.size();
        
        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {heights[i], i};
        }
        
        sort(v.begin(), v.end());
        
        vector<int> maxIdx(N); // maxIdx[i]: max({v[i].second, v[i + 1].second, ... , v[N - 1].second})
        vector<int> minIdx(N); // minIdx[i]: min({v[i].second, v[i + 1].second, ... , v[N - 1].second})
        maxIdx[N - 1] = v[N - 1].second;
        minIdx[N - 1] = v[N - 1].second;
        for(int i = N - 2; i >= 0; --i){
            maxIdx[i] = max(v[i].second, maxIdx[i + 1]);
            minIdx[i] = min(v[i].second, minIdx[i + 1]);
        }
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            int minHeight = v[i].first;
            int idxOfMinHeight = v[i].second;
            int maxWidth = max(abs(idxOfMinHeight - maxIdx[i]), abs(idxOfMinHeight - minIdx[i]));
            int area = minHeight * maxWidth;
            answer = max(area, answer);
        }
        
        return answer;
    }
};