class Solution {
public:

    struct point {
        int x, y, count, dir;

        string tostring() {
            return to_string(x) + " " + to_string(y) + " " + to_string(dir);
        };
    };


    int minimumMoves(vector<vector<int>> &grid) {
        int n = grid.size();
        int answer = -1;


        unordered_set<string> check;
        queue<point> q;
        q.push(point{0, 1, 0, 1});
        check.insert(point{0, 1, 0, 1}.tostring());
        while (!q.empty()) {
            point now = q.front();
            q.pop();


            if (now.x == n - 1 && now.y == n - 1 && now.dir) {
                answer = now.count;
                break;
            }
            //cout << now.tostring() << endl;
            if (now.dir) {
                if (now.y < n - 1 && grid[now.x][now.y + 1] == 0) {
                    point togo = point{now.x, now.y + 1, now.count + 1, 1};
                    if (check.find(togo.tostring()) == check.end()) {
                        q.push(togo);
                        check.insert(togo.tostring());
                    }
                }


                if (now.x < n - 1 && grid[now.x + 1][now.y - 1] == 0 && grid[now.x + 1][now.y] == 0) {
                    point togo = point{now.x + 1, now.y - 1, now.count + 1, 0};
                    if (check.find(togo.tostring()) == check.end()) {
                        q.push(togo);
                        check.insert(togo.tostring());
                    }
                    togo = point{now.x + 1, now.y, now.count + 1, 1};
                    if (check.find(togo.tostring()) == check.end()) {
                        q.push(togo);
                        check.insert(togo.tostring());
                    }
                }
            } else {
                if (now.x < n - 1 && grid[now.x + 1][now.y] == 0) {
                    point togo = point{now.x + 1, now.y, now.count + 1, false};
                    if (check.find(togo.tostring()) == check.end()) {
                        q.push(togo);
                        check.insert(togo.tostring());
                    }
                }

                if (now.y < n - 1 && grid[now.x - 1][now.y + 1] == 0 && grid[now.x][now.y + 1] == 0) {
                    point togo = point{now.x - 1, now.y + 1, now.count + 1, true};
                    if (check.find(togo.tostring()) == check.end()) {
                        q.push(togo);
                        check.insert(togo.tostring());
                    }
                    togo = point{now.x, now.y + 1, now.count + 1, 0};
                    if (check.find(togo.tostring()) == check.end()) {
                        q.push(togo);
                        check.insert(togo.tostring());
                    }
                }
            }
        }

        return answer;
    }
};