class Solution {
public:
    string reorganizeString(string s) {
        const int N = s.length();

        unordered_map<char, int> count;
        for(char c: s){
            count[c] += 1;
        }

        priority_queue<pair<int, char>> countCharMaxHeap;
        for(const pair<char, int>& P: count){
            char c = P.first;
            countCharMaxHeap.push({count[c], c});
        }

        string res;
        while((int)countCharMaxHeap.size() >= 2){
            char a = countCharMaxHeap.top().second;
            countCharMaxHeap.pop();

            char b = countCharMaxHeap.top().second;
            countCharMaxHeap.pop();

            res += a;
            res += b;

            count[a] -= 1;
            count[b] -= 1;

            if(count[a] >= 1){
                countCharMaxHeap.push({count[a], a});
            }
            if(count[b] >= 1){
                countCharMaxHeap.push({count[b], b});
            }
        }

        if((int)countCharMaxHeap.size() == 1){
            char a = countCharMaxHeap.top().second;
            if(count[a] == 1){
                count[a] -= 1;
                res += a;
            }else{
                res.clear();
            }
        }

        return res;
    }
};