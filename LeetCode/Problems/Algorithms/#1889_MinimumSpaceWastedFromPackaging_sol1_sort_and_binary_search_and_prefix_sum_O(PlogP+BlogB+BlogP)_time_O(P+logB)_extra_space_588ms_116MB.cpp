class Solution {
private:    
    long long computeWaste(vector<int>& sortedPackages, vector<long long>& packagesPrefSum, vector<int>& sortedBoxes){
        const int P = sortedPackages.size();
        if(sortedPackages.back() > sortedBoxes.back()){
            return -1;
        }
        
        long long waste = 0;
        int i = 0;
        for(int box: sortedBoxes){
            int j = upper_bound(sortedPackages.begin() + i, sortedPackages.end(), box) - sortedPackages.begin() - 1;
            long long rangeSum = 0;
            if(j >= 0){
                rangeSum += packagesPrefSum[j];
            }
            if(i - 1 >= 0){
                rangeSum -= packagesPrefSum[i - 1];
            }
            long long rangeSize = j - i + 1;
            waste += (box * rangeSize - rangeSum);
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
        const long long INF = LLONG_MAX / 10;
        const int MODULO = 1e9 + 7;
        
        sort(packages.begin(), packages.end());
        
        vector<long long> packagesPrefSum(P);
        packagesPrefSum[0] = packages[0];
        for(int i = 1; i < P; ++i){
            packagesPrefSum[i] = packagesPrefSum[i - 1] + packages[i];
        }
        
        long long minWaste = INF;
        for(vector<int>& boxes: allBoxes){
            sort(boxes.begin(), boxes.end());
            long long currentWaste = computeWaste(packages, packagesPrefSum, boxes);
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