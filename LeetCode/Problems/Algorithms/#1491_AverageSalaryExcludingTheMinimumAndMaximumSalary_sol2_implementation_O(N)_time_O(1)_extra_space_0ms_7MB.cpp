class Solution {
public:
    double average(vector<int>& salary) {
        const int N = salary.size();

        int minSalary = salary[0];
        int maxSalary = salary[0];
        int salarySum = 0;
        for(int s: salary){
            minSalary = min(minSalary, s);
            maxSalary = max(maxSalary, s);
            salarySum += s;
        }

        return (salarySum - minSalary - maxSalary) / (N - 2.0);
    }
};