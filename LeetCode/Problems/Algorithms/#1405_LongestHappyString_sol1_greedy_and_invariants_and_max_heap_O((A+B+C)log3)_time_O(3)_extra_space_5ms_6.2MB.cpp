class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap; // (charFreq, char)
        maxHeap.emplace(a, 'a');
        maxHeap.emplace(b, 'b');
        maxHeap.emplace(c, 'c');
        
        string res;
        while(true){
            int currentCharFreq = maxHeap.top().first;
            char currentChar = maxHeap.top().second;
            maxHeap.pop();
            
            int nextCharFreq = maxHeap.top().first;
            char nextChar = maxHeap.top().second;
            maxHeap.pop();
            
            if(currentCharFreq >= 1){
                int n = res.size();
                if(n <= 1 || res[n - 2] != currentChar || res[n - 1] != currentChar){
                    res += currentChar;
                    maxHeap.emplace(currentCharFreq - 1, currentChar);
                    maxHeap.emplace(nextCharFreq, nextChar);
                }else if(nextCharFreq >= 1){
                    res += nextChar;
                    maxHeap.emplace(currentCharFreq, currentChar);
                    maxHeap.emplace(nextCharFreq - 1, nextChar);
                }else{
                    break;
                }
            }else{
                break;
            }
        }
        
        return res;
    }
};