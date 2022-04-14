class Solution {
private:
    template <typename T>
    void kth_order_statistic(vector<T>& v, const int& L, const int& K, const int& R){
        int randPos = L + rand() % (R - L + 1);
        swap(v[randPos], v[R]);
        T pivot = v[R];
        
        int pos = L;
        for(int i = L; i <= R - 1; ++i){
            if(v[i] < pivot){
                swap(v[pos], v[i]);
                ++pos;
            }
        }
        
        swap(v[pos], v[R]);
        
        int pivotPos = pos;
        if(K < pivotPos){
            kth_order_statistic(v, L, K, pivotPos - 1);
        }else if(pivotPos < K){
            kth_order_statistic(v, pivotPos + 1, K, R);
        }
    }
    
    template <typename T>
    void kth_order_statistic(vector<T>& v, const int& K){
        srand(time(NULL));
        kth_order_statistic(v, 0, K, (int)v.size() - 1);
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, int> freqOf;
        for(int num: nums){
            freqOf[num] += 1;
        }
        
        vector<pair<int, int>> v;
        for(const pair<int, int>& P: freqOf){
            int num = P.first;
            int numFreq = P.second;
            v.emplace_back(numFreq, num);
        }
        
        kth_order_statistic(v, (int)v.size() - k);
        
        vector<int> res(k);
        for(int i = 0; i < k; ++i){
            res[i] = v[(int)v.size() - 1 - i].second;
        }
        
        return res;
    }
};