class Solution {
private:
    vector<int> extractRevisions(const string& S){
        const int N = S.length();

        vector<int> revisions;
        int r = 0;
        for(int i = 0; i < N; ++i){
            if(isdigit(S[i])){
                r = r * 10 + (S[i] - '0');
            }
            if(i == N - 1 || S[i + 1] == '.'){
                revisions.push_back(r);
                r = 0;
            }
        }

        while(!revisions.empty() && revisions.back() == 0){
            revisions.pop_back();
        }

        return revisions;
    }

public:
    int compareVersion(string version1, string version2) {
        vector<int> revisions1 = extractRevisions(version1);
        vector<int> revisions2 = extractRevisions(version2);

        if(revisions1 < revisions2){
            return -1;
        }else if(revisions1 > revisions2){
            return 1;
        }
        return 0;
    }
};