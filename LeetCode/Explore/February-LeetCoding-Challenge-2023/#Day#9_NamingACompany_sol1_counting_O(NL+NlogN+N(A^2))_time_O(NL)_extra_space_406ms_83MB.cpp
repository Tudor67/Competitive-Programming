class Solution {
private:
    long long computeContrib(vector<int>& v1, vector<int>& v2){
        // v1 and v2 are sorted in increasing order
        const int N1 = v1.size();
        const int N2 = v2.size();

        long long good1 = N1;
        long long good2 = N2;

        int p1 = 0;
        int p2 = 0;
        while(p1 < N1 && p2 < N2){
            if(v1[p1] < v2[p2]){
                p1 += 1;
            }else if(v1[p1] > v2[p2]){
                p2 += 1;
            }else{
                good1 -= 1;
                good2 -= 1;
                p1 += 1;
                p2 += 1;
            }
        }

        return good1 * good2;
    }

public:
    long long distinctNames(vector<string>& ideas) {
        const int N = ideas.size();
        const int A = 26;

        unordered_map<string, int> suffixToIndex;
        unordered_map<char, vector<int>> firstCharToSuffixIndices;
        for(int i = 0; i < N; ++i){
            string suffix = ideas[i].substr(1);
            if(!suffixToIndex.count(suffix)){
                suffixToIndex[suffix] = i;
            }
            firstCharToSuffixIndices[ideas[i][0]].push_back(suffixToIndex[suffix]);
        }

        for(char c = 'a'; c <= 'z'; ++c){
            if(firstCharToSuffixIndices.count(c)){
                vector<int>& v = firstCharToSuffixIndices[c];
                sort(v.begin(), v.end());
            }
        }

        long long res = 0;
        for(char c1 = 'a'; c1 <= 'z'; ++c1){
            for(char c2 = 'a'; c2 <= 'z'; ++c2){
                if(firstCharToSuffixIndices.count(c1) && firstCharToSuffixIndices.count(c2)){
                    res += computeContrib(firstCharToSuffixIndices[c1], firstCharToSuffixIndices[c2]);
                }
            }
        }

        return res;
    }
};