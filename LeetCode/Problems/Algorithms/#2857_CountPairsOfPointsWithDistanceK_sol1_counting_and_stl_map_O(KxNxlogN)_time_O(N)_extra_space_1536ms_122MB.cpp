class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        const int N = coordinates.size();

        int res = 0;
        map<pair<int, int>, int> f;

        for(int i = 0; i < N; ++i){
            int xi = coordinates[i][0];
            int yi = coordinates[i][1];

            for(int xContrib = 0; xContrib <= k; ++xContrib){
                int yContrib = k - xContrib;
                int xj = xi ^ xContrib;
                int yj = yi ^ yContrib;
                if(f.count({xj, yj})){
                    res += f[{xj, yj}];
                }
            }
            
            f[{xi, yi}] += 1;
        }

        return res;
    }
};