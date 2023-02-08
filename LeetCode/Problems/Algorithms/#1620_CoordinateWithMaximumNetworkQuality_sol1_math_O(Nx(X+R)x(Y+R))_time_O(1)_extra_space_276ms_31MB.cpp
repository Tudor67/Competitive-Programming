class Solution {
private:
    using Point = vector<int>;

    double getDist(const Point& A, const Point& B){
        double dx = A[0] - B[0];
        double dy = A[1] - B[1];
        return sqrt(dx * dx + dy * dy);
    }

    int getQuality(const Point& P, vector<vector<int>>& towers, int radius){
        int quality = 0;
        for(const vector<int>& T: towers){
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

        int maxX = 0;
        int maxY = 0;
        for(const Point& P: towers){
            maxX = max(maxX, P[0]);
            maxY = max(maxY, P[1]);
        }

        Point resPoint = {0, 0};
        int resQuality = getQuality(resPoint, towers, radius);
        for(int x = 0; x <= maxX + radius; ++x){
            for(int y = 0; y <= maxY + radius; ++y){
                int quality = getQuality({x, y}, towers, radius);
                if(quality > resQuality){
                    resQuality = quality;
                    resPoint = {x, y};
                }
            }
        }

        return resPoint;
    }
};