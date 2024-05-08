class Solution {
private:
    int nextRevision(string& version, int& i){
        const int L = version.length();

        int r = 0;
        while(i < L && isdigit(version[i])){
            r = r * 10 + (version[i] - '0');
            i += 1;
        }

        if(i < L){
            i += 1;
        }

        return r;
    }

public:
    int compareVersion(string version1, string version2) {
        const int L1 = version1.length();
        const int L2 = version2.length();

        int i1 = 0;
        int i2 = 0;
        int r1 = 0;
        int r2 = 0;
        while(r1 == r2 && (i1 < L1 || i2 < L2)){
            r1 = nextRevision(version1, i1);
            r2 = nextRevision(version2, i2);
        }

        if(r1 < r2){
            return -1;
        }else if(r1 > r2){
            return 1;
        }
        return 0;
    }
};