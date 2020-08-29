class Solution {
private:
    const int N;
    vector<vector<int>> rects;
    vector<int> pref_sum;
    
    static int area(const vector<int>& RECT){
        return (RECT[2] - RECT[0] + 1) * (RECT[3] - RECT[1] + 1);
    }
    
public:
    Solution(vector<vector<int>>& rects): N(rects.size()) {
        this->rects = rects;
        pref_sum.resize(N, 0);
        pref_sum[0] = area(rects[0]);
        for(int i = 1; i < N; ++i){
            pref_sum[i] = pref_sum[i - 1] + area(rects[i]);
        }
        srand(time(NULL));
    }
    
    vector<int> pick() {
        int rand_val = rand() % pref_sum[N - 1];
        int idx = upper_bound(pref_sum.begin(), pref_sum.end(), rand_val) - pref_sum.begin();
        int rect_width = rects[idx][2] - rects[idx][0] + 1;
        int point_pos = rand_val - (idx >= 1 ? pref_sum[idx - 1] : 0);
        int point_x = rects[idx][0] + point_pos % rect_width;
        int point_y = rects[idx][1] + point_pos / rect_width;
        return {point_x, point_y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */