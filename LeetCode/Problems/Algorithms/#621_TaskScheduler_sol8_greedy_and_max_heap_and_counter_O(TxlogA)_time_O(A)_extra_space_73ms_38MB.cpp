class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        const int T = tasks.size();
        const int A = 26;
        
        unordered_map<char, int> freqOf;
        for(char c: tasks){
            freqOf[c] += 1;
        }

        priority_queue<int> maxHeap;
        for(const pair<const char, int>& P: freqOf){
            maxHeap.push(P.second);
        }

        int res = 0;
        vector<int> tempVector;
        while(!maxHeap.empty()){
            int contrib = 0;
            while(!maxHeap.empty() && contrib < n + 1){
                int f = maxHeap.top();
                maxHeap.pop();

                contrib += 1;

                if(f - 1 >= 1){
                    tempVector.push_back(f - 1);
                }
            }

            while(!tempVector.empty()){
                maxHeap.push(tempVector.back());
                tempVector.pop_back();
            }

            if(!maxHeap.empty()){
                res += n + 1;
            }else{
                res += contrib;
            }
        }

        return res;
    }
};