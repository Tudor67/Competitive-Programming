class Solution {
private:
    void countSort(vector<int>& v){
        const int N = v.size();
        const int MAX_ELEM = *max_element(v.begin(), v.end());
        
        vector<int> count(MAX_ELEM + 1);
        for(int elem: v){
            count[elem] += 1;
        }
        
        int idx = 0;
        for(int elem = 0; elem <= MAX_ELEM; ++elem){
            while(count[elem] > 0){
                v[idx] = elem;
                idx += 1;
                count[elem] -= 1;
            }
        }
    }
    
public:
    long long maximumImportance(int N, vector<vector<int>>& roads) {
        vector<int> degree(N);
        for(const vector<int>& ROAD: roads){
            int a = ROAD[0];
            int b = ROAD[1];
            degree[a] += 1;
            degree[b] += 1;
        }
        
        countSort(degree);
        
        long long res = 0;
        for(int i = 0; i < N; ++i){
            res += degree[i] * (i + 1LL);
        }
        
        return res;
    }
};