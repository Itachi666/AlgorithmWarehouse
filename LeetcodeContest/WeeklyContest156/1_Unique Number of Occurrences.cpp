class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> check;
        for (int i:arr)
            if (check.find(i) == check.end())
                check[i]=1;
            else
                check[i]++;
        set<int> t;
        for (map<int, int>::iterator iter=check.begin(); iter!=check.end(); iter++)
            if (t.find(iter->second) == t.end())
                t.insert(iter->second);
            else
                return false;
        return true;
    }
};