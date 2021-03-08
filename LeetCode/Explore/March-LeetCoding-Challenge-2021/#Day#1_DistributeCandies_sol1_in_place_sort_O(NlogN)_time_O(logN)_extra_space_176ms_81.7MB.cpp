class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        const int N = candyType.size();
        sort(candyType.begin(), candyType.end());
        
        int distinctTypes = 1;
        for(int i = 1; i < N; ++i){
            distinctTypes += (candyType[i - 1] != candyType[i]);
        }
        
        int answer = min(N / 2, distinctTypes);
        
        return answer;
    }
};