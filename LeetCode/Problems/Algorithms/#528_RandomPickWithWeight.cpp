class Solution {
private:
    static const int MAX_VAL = 10000;
    const int N;
    vector<double> p;
    
public:
    Solution(vector<int>& w): N(w.size()) {
        double total_sum = accumulate(w.begin(), w.end(), 0);
        double current_sum = 0;
        p.resize(N + 1, 0);
        for(int i = 1; i <= N; ++i){
            current_sum += w[i - 1];
            p[i] = current_sum / total_sum;
        }
        srand(time(NULL));
    }
    
    int pickIndex() {
        double x = (rand() % MAX_VAL) / double(MAX_VAL);
        int idx = upper_bound(p.begin(), p.end(), x) - p.begin() - 1;
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */