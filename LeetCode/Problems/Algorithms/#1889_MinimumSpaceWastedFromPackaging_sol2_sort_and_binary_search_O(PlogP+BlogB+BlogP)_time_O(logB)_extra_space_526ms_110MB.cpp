class Solution {
private:    
    long long computeWaste(vector<int>& sortedPackages, const long long& TOTAL_PACKAGES, vector<int>& sortedBoxes){
        const int P = sortedPackages.size();
        if(sortedPackages.back() > sortedBoxes.back()){
            return -1;
        }
        
        long long waste = -TOTAL_PACKAGES;
        int i = 0;
        for(int box: sortedBoxes){
            int j = upper_bound(sortedPackages.begin() + i, sortedPackages.end(), box) - sortedPackages.begin() - 1;
            long long rangeSize = j - i + 1;
            waste += box * rangeSize;
            i = j + 1;
            if(i >= P){
                break;
            }
        }
        
        return waste;
    }
    
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& allBoxes) {
        const int P = packages.size();
        const long long TOTAL_PACKAGES = accumulate(packages.begin(), packages.end(), 0LL);
        const long long INF = LLONG_MAX / 10;
        const int MODULO = 1e9 + 7;
        
        sort(packages.begin(), packages.end());
        
        long long minWaste = INF;
        for(vector<int>& boxes: allBoxes){
            sort(boxes.begin(), boxes.end());
            long long currentWaste = computeWaste(packages, TOTAL_PACKAGES, boxes);
            if(currentWaste != -1){
                minWaste = min(minWaste, currentWaste);
            }
        }
        
        if(minWaste == INF){
            minWaste = -1;
        }
        
        return minWaste % MODULO;
    }
};