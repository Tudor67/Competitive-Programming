class Solution {
private:
    void computeSides(vector<int> fences, const int MAX_COORDINATE, vector<int>& sides){
        fences.push_back(1);
        fences.push_back(MAX_COORDINATE);
        
        sides.clear();
        for(int i = 0; i < (int)fences.size(); ++i){
            for(int j = i + 1; j < (int)fences.size(); ++j){
                sides.push_back(abs(fences[j] - fences[i]));
            }
        }
    }
    
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MODULO = 1e9 + 7;

        vector<int> hSides;
        vector<int> vSides;
        computeSides(hFences, m, hSides);
        computeSides(vFences, n, vSides);

        sort(vSides.begin(), vSides.end());
        vSides.resize(unique(vSides.begin(), vSides.end()) - vSides.begin());
        
        long long maxSqArea = -1;
        for(int side: hSides){
            if(binary_search(vSides.begin(), vSides.end(), side)){
                long long area = (long long)side * (long long)side;
                maxSqArea = max(maxSqArea, area);
            }
        }
        
        return maxSqArea % MODULO;
    }
};