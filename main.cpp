#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
//#include "src/TypeConverter.cpp"

using namespace std;

vector<int> stringToIntegerVector(string input);

class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        map<int, int> times;

        map<int, vector<int>> list;

        int answer = 0;
        times[0] = 0;
        for (int i = 0; i < startTime.size(); i++) {
            times[endTime[i]] = 0;
            list[endTime[i]].push_back(i);
        }

        for (auto e:list) {
            for (auto i:e.second) {
                auto t = times.upper_bound(startTime[i]);
                t--;
                cout << t->first << endl;
                answer = max(answer, t->second + profit[i]);


                printf("%d %d\n", endTime[i], times[endTime[i]]);
            }
            times[e.first] = answer;
        }


        return answer;
    }
};

int main() {
    freopen("1.in", "r", stdin);
    string line;
    while (getline(cin, line)) {
        vector<int> startTime = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> endTime = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> profit = stringToIntegerVector(line);

        int ret = Solution().jobScheduling(startTime, endTime, profit);

        string out = to_string(ret);
        cout << out << endl;
    }

    return 0;
}