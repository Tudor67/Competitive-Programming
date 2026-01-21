class Solution {
private:
    vector<int> computeGaps(vector<int> fences, int border){
        fences.push_back(1);
        fences.push_back(border);

        vector<int> gaps;
        gaps.reserve(fences.size() * fences.size());
        for(int i = 0; i < (int)fences.size(); ++i){
            for(int j = i + 1; j < (int)fences.size(); ++j){
                gaps.push_back(abs(fences[j] - fences[i]));
            }
        }

        return gaps;
    }

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vector<int> hGaps = computeGaps(hFences, m);
        vector<int> vGaps = computeGaps(vFences, n);
        unordered_set<int> vGapsSet(vGaps.begin(), vGaps.end());

        long long maxSqArea = -1;
        for(long long hGap: hGaps){
            if(vGapsSet.count(hGap)){
                maxSqArea = max(maxSqArea, hGap * hGap);
            }
        }

        return maxSqArea % 1'000'000'007;
    }
};