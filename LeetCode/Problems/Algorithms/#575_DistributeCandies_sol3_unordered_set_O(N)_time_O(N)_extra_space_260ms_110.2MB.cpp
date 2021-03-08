class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        const int DISTINCT_TYPES = unordered_set<int>(candyType.begin(), candyType.end()).size();
        const int N = candyType.size();
        int answer = min(N / 2, DISTINCT_TYPES);
        return answer;
    }
};