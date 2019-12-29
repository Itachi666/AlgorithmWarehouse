class Solution {
public:
    unordered_map<char, int> a;
    vector<bool> used;

    bool ans = false;
    int maxLen = 0, n;
    vector<int> last;

    int str2num(string s) {
        int num = 0;
        for (int i = s.length() - 1; i >= 0; i--)
            num = num * 10 + a[s[i]];
        return num;
    }

    bool check(vector<string> &words, string result) {
        int count = 0;
        for (auto &s:words) {
            if (a[s[s.length()-1]]==0)
                return false;
            count += str2num(s);
        }

        if (a[result[result.length()-1]]==0)
            return false;

        return count == str2num(result);
    }

    void output(vector<string> &words, string result) {
        for (auto& s:words) {
            for (int i = 0; i < s.length(); i++)
                if (a[s[i]] != -1)
                    cout << a[s[i]];
                else
                    cout << s[i];
            cout<<endl;
        }
        for (int i = 0; i < result.length(); i++)
            if (a[result[i]] != -1)
                cout << a[result[i]];
            else
                cout << result[i];
        cout<<endl;
    }

    void dfs(int x, int b, vector<string> &words, string result) {
        if (ans)
            return;

        if (b == maxLen) {
            ans = check(words, result);
            return;
        }

        if (x < n) {
            string &s = words[x];

            if (s.length() <= b) {
                dfs(x + 1, b, words, result);
                return;
            }

            if (a[s[b]] != -1) {
                dfs(x + 1, b, words, result);
                return;
            }

            int begin=0;
            if (s.length()-1==b)
                begin=1;
            for (int i = begin; i < 10; i++)
                if (used[i] == false) {
                    used[i] = true;
                    a[s[b]] = i;

                    dfs(x + 1, b, words, result);
                    a[s[b]] = -1;
                    used[i] = false;
                }
        }
        if (x == n) {
            string &s = result;

            int count = last[b];
            for (auto &t:words) {
                if (t.length() > b)
                    count += a[t[b]];
            }

            last[b+1] = count / 10;
            count = count % 10;

            if (a[s[b]] != -1 && a[s[b]] != count)
                return;

            if (a[s[b]] == -1 && used[count])
                return;


            if (a[s[b]] == -1) {
                used[count] = true;
                a[s[b]] = count;

                dfs(0, b + 1, words, result);
                used[count] = false;
                a[s[b]] = -1;
            } else {
                dfs(0, b + 1, words, result);
            }
        }
    }

    bool isSolvable(vector<string> &words, string result) {
        n = words.size();
        used.clear();
        used.resize(10, false);
        last.clear();
        last.resize(10, 0);

        reverse(result.begin(), result.end());
        for (auto &c:result)
            a[c] = -1;

        maxLen = max(maxLen, (int) result.size());

        for (auto &s:words) {
            reverse(s.begin(), s.end());
            for (auto &c:s)
                a[c] = -1;
            maxLen = max(maxLen, (int) s.size());
        }

        if (maxLen != result.size())
            return false;

        dfs(0, 0, words, result);

        return ans;
    }
};