class Solution {
private:
    using Point = vector<int>;

    double getDist(const Point& A, const Point& B){
        double dx = A[0] - B[0];
        double dy = A[1] - B[1];
        return sqrt(dx * dx + dy * dy);
    }

    int getQuality(const Point& P, vector<vector<int>>& towers, int startIndex, int endIndex, int radius){
        int quality = 0;
        for(int i = startIndex; i < endIndex; ++i){
            const vector<int>& T = towers[i];
            double d = getDist(P, T);
            if(d <= radius){
                double q = T[2];
                quality += (int)(q / (1 + d));
            }
        }
        return quality;
    }

public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        const int N = towers.size();

        sort(towers.begin(), towers.end());

        int maxX = 0;
        int maxY = 0;
        for(const vector<int>& T: towers){
            maxX = max(maxX, T[0]);
            maxY = max(maxY, T[1]);
        }

        Point resPoint = {0, 0};
        int resQuality = getQuality(resPoint, towers, 0, N, radius);
        int l = 0;
        int r = 0;
        for(int x = 0; x <= maxX + radius; ++x){
            while(l < N && towers[l][0] + radius < x){
                l += 1;
            }
            while(r < N && towers[r][0] - radius <= x){
                r += 1;
            }
            for(int y = 0; y <= maxY + radius; ++y){
                int quality = getQuality({x, y}, towers, l, r, radius);
                if(quality > resQuality){
                    resQuality = quality;
                    resPoint = {x, y};
                }
            }
        }

        return resPoint;
    }
};