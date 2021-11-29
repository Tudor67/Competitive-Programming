class Solution {
private:
    pair<int, int> computeIntersection(const vector<int>& SEG1, const vector<int>& SEG2){
        return {max(SEG1[0], SEG2[0]), min(SEG1[1], SEG2[1])};
    }
    
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        const int N1 = firstList.size();
        const int N2 = secondList.size();
        
        vector<vector<int>> intersections;
        int firstIdx = 0;
        int secondIdx = 0;
        while(firstIdx < N1 && secondIdx < N2){
            pair<int, int> intersection = computeIntersection(firstList[firstIdx], secondList[secondIdx]);
            if(intersection.first <= intersection.second){
                intersections.push_back({intersection.first, intersection.second});
            }
            if(firstList[firstIdx][1] <= secondList[secondIdx][1]){
                firstIdx += 1;
            }else{
                secondIdx += 1;
            }
        }
        
        return intersections;
    }
};