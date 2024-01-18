#include <bits/stdc++.h>
using namespace std;

string add(string A, string B){
    const int A_LEN = A.length();
    const int B_LEN = B.length();
    const int C_LEN = max(A_LEN, B_LEN);

    string C(C_LEN, '0');
    int carry = 0;
    for(int i = 0; i < C_LEN; ++i){
        int digitA = (i <= A_LEN - 1 ? A[A_LEN - 1 - i] - '0' : 0);
        int digitB = (i <= B_LEN - 1 ? B[B_LEN - 1 - i] - '0' : 0);
        int sum = (carry + digitA + digitB);
        C[C_LEN - 1 - i] = char('0' + (sum % 10));
        carry = sum / 10;
    }

    if(carry > 0){
        C.insert(C.begin(), char(carry + '0'));
    }

    return C;
}

string mult(string A, string B){
    const int A_LEN = A.length();
    const int B_LEN = B.length();

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    vector<int> sum(A_LEN + B_LEN + 1);
    for(int i = 0; i < A_LEN; ++i){
        for(int j = 0; j < B_LEN; ++j){
            sum[i + j] += (A[i] - '0') * (B[j] - '0');
        }
    }

    for(int i = 0; i + 1 < (int)sum.size(); ++i){
        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
    }

    while(!sum.empty() && sum.back() == 0){
        sum.pop_back();
    }

    string C;
    C.reserve(sum.size());
    while(!sum.empty()){
        C.push_back(char('0' + sum.back()));
        sum.pop_back();
    }

    return C;
}

bool isLessOrEqual(const string& A, const string& B){
    if(A.length() < B.length()){
        return true;
    }
    if(A.length() == B.length()){
        return (A <= B);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string rStr;
    cin >> rStr;

    long long N;
    cin >> N;

    long long rX = 0;
    long long rY = 1;
    for(int i = 2; i < (int)rStr.length(); ++i){
        rX = rX * 10 + (rStr[i] - '0');
        rY = rY * 10;
    }

    long long g = gcd(rX, rY);
    rX /= g;
    rY /= g;

    if(rY <= N){
        cout << rX << " " << rY;
        return 0;
    }
    
    long long a = 0;
    long long b = 1;
    long long c = 1;
    long long d = 0;
    while(b + d <= N){
        long long x = a + c;
        long long y = b + d;
        string lStr = mult(to_string(x), to_string(rY));
        string rStr = mult(to_string(rX), to_string(y));
        if(lStr == rStr){
            a = x;
            b = y;
            c = x;
            d = y;
            break;
        }else if(isLessOrEqual(lStr, rStr)){
            long long l = 0;
            long long r = (N - b) / d;
            while(l != r){
                long long mid = (l + r + 1) / 2;
                long long xMid = a + mid * c;
                long long yMid = b + mid * d;
                string lStr = mult(to_string(xMid), to_string(rY));
                string rStr = mult(to_string(rX), to_string(yMid));
                if(isLessOrEqual(lStr, rStr)){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            a = a + r * c;
            b = b + r * d;
        }else{
            long long l = 0;
            long long r = (N - d) / b;
            while(l != r){
                long long mid = (l + r + 1) / 2;
                long long xMid = mid * a + c;
                long long yMid = mid * b + d;
                string lStr = mult(to_string(xMid), to_string(rY));
                string rStr = mult(to_string(rX), to_string(yMid));
                if(isLessOrEqual(lStr, rStr)){
                    r = mid - 1;
                }else{
                    l = mid;
                }
            }
            c = r * a + c;
            d = r * b + d;
        }
    }

    string l = mult(to_string(2 * b), to_string(d));
    l = mult(l, to_string(rX));

    string r1 = to_string(rY);
    string r2 = add(mult(to_string(a), to_string(d)),
                    mult(to_string(c), to_string(b)));
    string r = mult(r1, r2);

    if(isLessOrEqual(l, r)){
        cout << a << " " << b;
    }else{
        cout << c << " " << d;
    }

    return 0;
}