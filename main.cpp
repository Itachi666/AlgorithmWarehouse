#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <set>
#include <stack>
//#include "src/TypeConverter.cpp"

using namespace std;

vector<int> stringToIntegerVector(string input);

class Solution {
public:
    int gcd(int x, int y) {
        return (x%y)? gcd(y, x%y) : y;
    }

    bool isGoodArray(vector<int>& nums) {
        return false;
    }
};

void Leetcode_cin() {
    freopen("1.in", "r", stdin);
    string line;
    while (getline(cin, line)) {
        getline(cin, line);

        vector<int> v = stringToIntegerVector(line);
        cout<<endl<<line<<endl;

        Solution().isGoodArray(v);
        cout<<Solution().gcd(56,31)<<endl;

    }
}

void nth()
{
    std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};

    std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
    std::cout << "The median is " << v[v.size()/2] << '\n';

    for (auto it:v)
        cout<<it<<' ';
    cout<<endl;

    std::nth_element(v.begin(), v.begin()+3, v.end(), greater<int>());
    std::cout << "The second largest element is " << v[1] << '\n';

    for (auto it:v)
        cout<<it<<' ';
    cout<<endl;
}

int main() {
    nth();
    return 0;
}