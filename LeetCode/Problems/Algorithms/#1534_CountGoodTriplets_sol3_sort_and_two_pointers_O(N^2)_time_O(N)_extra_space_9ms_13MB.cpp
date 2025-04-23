class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        const int N = arr.size();

        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {arr[i], i};
        }

        sort(v.begin(), v.end());

        int goodTriplets = 0;
        vector<int> l;
        vector<int> r;

        for(auto& [_, j]: v){
            l.clear();
            for(auto& [_, i]: v){
                if(i < j && abs(arr[i] - arr[j]) <= a){
                    l.push_back(i);
                }
            }

            r.clear();
            for(auto& [_, k]: v){
                if(j < k && abs(arr[j] - arr[k]) <= b){
                    r.push_back(k);
                }
            }
            
            int rIndex1 = 0;
            int rIndex2 = 0;
            for(int i: l){
                while(rIndex1 < (int)r.size() && arr[r[rIndex1]] - arr[i] < -c){
                    rIndex1 += 1;
                }
                while(rIndex2 < (int)r.size() && arr[r[rIndex2]] - arr[i] <= c){
                    rIndex2 += 1;
                }
                goodTriplets += (rIndex2 - rIndex1);
            }
        }

        return goodTriplets;
    }
};