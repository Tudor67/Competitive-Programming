class Solution {
public:
    string frequencySort(string s) {
        const int N = s.length();
        const int A = 126;
        
        vector<int> charCount(A, 0);
        for(char c: s){
            charCount[c] += 1;
        }
        
        priority_queue<pair<int, int>> maxHeap;
        for(char c = 0; c < A; ++c){
            if(charCount[c] > 0){
                maxHeap.push({charCount[c], c});
            }
        }
        
        string sortedS;
        while(!maxHeap.empty()){
            int freq = maxHeap.top().first;
            int c = maxHeap.top().second;
            maxHeap.pop();
            sortedS.append(freq, c);
        }
        
        return sortedS;
    }
};