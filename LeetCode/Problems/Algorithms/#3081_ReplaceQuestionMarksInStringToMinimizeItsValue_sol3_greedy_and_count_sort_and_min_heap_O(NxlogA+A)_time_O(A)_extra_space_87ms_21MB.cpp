class Solution {
public:
    string minimizeStringValue(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> freq(A);
        for(char c: s){
            if(c != '?'){
                freq[c - 'a'] += 1;
            }
        }

        using PIC = pair<int, char>;
        priority_queue<PIC, vector<PIC>, greater<PIC>> minHeap;
        for(char c = 'a'; c <= 'z'; ++c){
            minHeap.push({freq[c - 'a'], c});
        }

        vector<int> specialFreq(A);
        for(char c: s){
            if(c == '?'){
                c = minHeap.top().second;
                minHeap.pop();

                freq[c - 'a'] += 1;
                specialFreq[c - 'a'] += 1;

                minHeap.push({freq[c - 'a'], c});
            }
        }

        int i = 0;
        for(char& c: s){
            if(c == '?'){
                while(specialFreq[i] == 0){
                    i += 1;
                }
                c = char('a' + i);
                specialFreq[i] -= 1;
            }
        }

        return s;
    }
};