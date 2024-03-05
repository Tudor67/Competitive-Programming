class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        const int N = coordinates.size();

        int res = 0;
        map<int, map<int, int>> f;

        for(int i = 0; i < N; ++i){
            int xi = coordinates[i][0];
            int yi = coordinates[i][1];

            auto itStart = f.lower_bound(xi - k);
            auto itEnd = f.upper_bound(xi + k);
            for(auto it = itStart; it != itEnd; ++it){
                int xj = it->first;
                int yj = (k - (xi ^ xj)) ^ yi;
                if(it->second.count(yj)){
                    res += it->second[yj];
                }
            }
            
            f[xi][yi] += 1;
        }

        return res;
    }
};