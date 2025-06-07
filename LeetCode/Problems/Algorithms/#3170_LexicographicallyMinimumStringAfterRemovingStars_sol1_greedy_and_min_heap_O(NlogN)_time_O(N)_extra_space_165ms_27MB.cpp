class Solution {
public:
    string clearStars(string s) {
        const int N = s.length();

        using PCI = pair<char, int>;
        priority_queue<PCI, vector<PCI>, greater<PCI>> minHeap;
        vector<bool> isErased(N, false);

        for(int i = 0; i < N; ++i){
            if(s[i] == '*'){
                isErased[i] = true;
                isErased[-minHeap.top().second] = true;
                minHeap.pop();
            }else{
                minHeap.push({s[i], -i});
            }
        }

        string res;
        for(int i = 0; i < N; ++i){
            if(!isErased[i]){
                res += s[i];
            }
        }

        return res;
    }
};