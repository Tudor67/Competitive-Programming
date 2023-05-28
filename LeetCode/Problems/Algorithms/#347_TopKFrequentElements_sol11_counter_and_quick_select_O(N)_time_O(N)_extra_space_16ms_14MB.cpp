class Solution {
private:
    template <typename T>
    void quickSelect(vector<T>& v, const int L, const int K, const int R){
        if(L >= R){
            return;
        }

        int randIndex = L + rand() % (R - L + 1);
        swap(v[randIndex], v[R]);
        T pivot = v[R];

        int l = L;
        int r = R;
        while(l < r){
            if(v[l] < pivot){
                l += 1;
            }else{
                r -= 1;
                swap(v[l], v[r]);
            }
        }

        int pivotIndex = r;
        swap(v[pivotIndex], v[R]);

        // v[L .. pivotIndex - 1] < pivot
        // v[pivotIndex] == pivot
        // v[pivotIndex + 1 .. R] >= pivot

        if(pivotIndex < K){
            quickSelect(v, pivotIndex + 1, K, R);
        }else if(pivotIndex == K){
            return;
        }else if(K < pivotIndex){
            quickSelect(v, L, K, pivotIndex - 1);
        }
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int N = nums.size();

        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }

        vector<pair<int, int>> v;
        for(const pair<int, int>& P: count){
            int num = P.first;
            int numCount = P.second;
            v.push_back({numCount, num});
        }

        srand(time(nullptr));
        quickSelect(v, 0, (int)v.size() - k, (int)v.size() - 1);

        vector<int> res(k);
        for(int i = 0; i < k; ++i){
            res[i] = v[(int)v.size() - 1 - i].second;
        }

        return res;
    }
};