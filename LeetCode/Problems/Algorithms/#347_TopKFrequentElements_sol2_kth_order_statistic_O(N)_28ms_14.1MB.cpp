class Solution {
private:
    void kth_order_statistic(vector<pair<int, int>>& v, const int& L, const int& K, const int& R){
        // pick a random pivot in the range [L, R]
        int pivot_idx = L + rand() % (R - L + 1);
        pair<int, int> pivot = v[pivot_idx];
        
        // move pivot to end
        swap(v[pivot_idx], v[R]);
        
        // move all less frequent elements to the left
        int idx = L;
        for(int i = L; i < R; ++i){
            if(v[i].first < pivot.first){
                swap(v[i], v[idx]);
                idx += 1;
            }
        }
        
        // move pivot to its final place
        swap(v[idx], v[R]);
        pivot_idx = idx;
        
        if(pivot_idx < K){
            kth_order_statistic(v, pivot_idx + 1, K, R);
        }
        if(K < pivot_idx){
            kth_order_statistic(v, L, K, pivot_idx - 1);
        }
    }
    
    void kth_order_statistic(vector<pair<int, int>>& v, const int& K){
        srand(time(NULL));
        kth_order_statistic(v, 0, K, (int)v.size() - 1);
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int num: nums){
            cnt[num] += 1;
        }
        
        // vector of unique pairs: (frequency, element)
        vector<pair<int, int>> v;
        for(const pair<int, int>& p: cnt){
            int freq = p.second;
            int elem = p.first;
            v.push_back({freq, elem});
        }
        
        // (N - K)th order statistic
        kth_order_statistic(v, (int)v.size() - k);
        
        vector<int> answer;
        for(int i = (int)v.size() - 1; i >= (int)v.size() - k; --i){
            answer.push_back(v[i].second);
        }
        
        return answer;
    }
};