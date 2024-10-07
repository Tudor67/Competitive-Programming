class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        const int N = arr.size();

        map<int, int> rankOf;
        for(int elem: arr){
            rankOf[elem] = 1;
        }

        int prevRank = 0;
        for(pair<const int, int>& P: rankOf){
            int& currRank = P.second;
            currRank = prevRank + 1;
            prevRank = currRank;
        }

        vector<int> rank(N);
        for(int i = 0; i < N; ++i){
            rank[i] = rankOf[arr[i]];
        }

        return rank;
    }
};