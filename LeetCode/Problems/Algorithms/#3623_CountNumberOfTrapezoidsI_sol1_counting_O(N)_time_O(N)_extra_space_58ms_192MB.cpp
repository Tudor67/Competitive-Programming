class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MODULO = 1'000'000'007;

        unordered_map<int, int> freq;
        for(vector<int>& point: points){
            int y = point[1];
            freq[y] += 1;
        }

        int hTrapezoids = 0;
        int hPairs = 0;
        for(auto& [y, yFreq]: freq){
            int hPairsY = (yFreq - 1) * (long long)yFreq / 2 % MODULO;
            hTrapezoids = (hTrapezoids + hPairs * (long long)hPairsY) % MODULO;
            hPairs = (hPairs + hPairsY) % MODULO;
        }

        return hTrapezoids;
    }
};