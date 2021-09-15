class Solution {
private:
    vector<int> getCounter(const string& S){
        vector<int> count(26, 0);
        for(char c: S){
            count[c - 'a'] += 1;
        }
        return count;
    }
    
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count = getCounter(text);
        vector<int> targetCount = getCounter("balloon");
        int answer = INT_MAX;
        for(int i = 0; i < (int)targetCount.size(); ++i){
            if(targetCount[i] > 0){
                answer = min(answer, count[i] / targetCount[i]);
            }
        }
        return answer;
    }
};