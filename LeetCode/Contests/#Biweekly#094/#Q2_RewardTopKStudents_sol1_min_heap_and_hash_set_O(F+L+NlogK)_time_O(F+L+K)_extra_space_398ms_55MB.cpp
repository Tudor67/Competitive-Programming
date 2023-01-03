class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        const int N = report.size();
        
        unordered_set<string> posSet(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negSet(negative_feedback.begin(), negative_feedback.end());
        
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;
        for(int i = 0; i < N; ++i){
            int score = 0;
            string currentWord;
            istringstream iss(report[i]);
            while(iss >> currentWord){
                if(posSet.count(currentWord)){
                    score += 3;
                }else if(negSet.count(currentWord)){
                    score -= 1;
                }
            }

            minHeap.push({score, -student_id[i]});
            if((int)minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> res(k);
        for(int i = k - 1; i >= 0; --i){
            res[i] = -minHeap.top().second;
            minHeap.pop();
        }
        
        return res;
    }
};