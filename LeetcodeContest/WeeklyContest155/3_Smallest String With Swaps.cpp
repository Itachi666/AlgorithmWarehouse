class Solution {
public:
    int father[100002] = {0};

    int find(int x) {
        return father[x] == x ? x : father[x] = find(father[x]);
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        for (int i = 0; i < s.length(); i++)
            father[i] = i;

        for (int i = 0; i < pairs.size(); i++)
            if (find(pairs[i][0]) != find(pairs[i][1]))
                father[find(pairs[i][1])] = find(pairs[i][0]);

        vector<int> t;
        vector<vector<int>> tmpint;
        vector<vector<char>> tmp;
        map<int, int> h;

        for (int i = 0; i < s.length(); i++) {
            int fa = find(i);
            if (h.find(fa) == h.end()) {

                t.push_back(fa);
                vector<char> kkk;
                kkk.push_back(s[i]);
                tmp.push_back(kkk);

                vector<int> vvv;
                vvv.push_back(i);
                tmpint.push_back(vvv);

                h[fa] = tmp.size() - 1;
            } else {
                tmp[h[fa]].push_back(s[i]);
                tmpint[h[fa]].push_back(i);
            }
        }

        for (int i = 0; i < tmp.size(); i++)
            sort(tmp[i].begin(), tmp[i].end());

        for (int i = 0; i < t.size(); i++) {
            int tochar = h[t[i]];
            for (int j = 0; j < tmpint[tochar].size(); j++)
                s[tmpint[tochar][j]] = tmp[tochar][j];
        }

        return s;
    }
};