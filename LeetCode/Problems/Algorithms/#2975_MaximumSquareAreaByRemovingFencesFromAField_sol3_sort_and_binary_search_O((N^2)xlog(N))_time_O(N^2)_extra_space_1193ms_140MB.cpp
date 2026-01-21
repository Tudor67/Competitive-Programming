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

        sort(gaps.begin(), gaps.end());
        gaps.resize(unique(gaps.begin(), gaps.end()) - gaps.begin());

        return gaps;
    }

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vector<int> hGaps = computeGaps(hFences, m);
        vector<int> vGaps = computeGaps(vFences, n);

        for(int i = (int)hGaps.size() - 1; i >= 0; --i){
            if(binary_search(vGaps.begin(), vGaps.end(), hGaps[i])){
                return (long long)hGaps[i] * (long long)hGaps[i] % 1'000'000'007;
            }
        }

        return -1;
    }
};