// Algorithm: DP
// Runtime: 24 ms
// Memory Usage: 10.6 MB

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int ans=0, n=matrix.size(), m=matrix[0].size();

        int left[m]={0}, right[m]={0}, height[m]={0};

        for (int i=0;i<m;i++)
        {
            left[i]=0x7fffffff;
            right[i]=0x7fffffff;
        }

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (matrix[i][j]=='1') {
                    height[j]++;

                    int k=j;
                    while (k>=0 && matrix[i][k]=='1') {
                        k--;
                    }
                    left[j]=min(left[j], j-k-1);

                    k=j;
                    while (k<m && matrix[i][k]=='1') {
                        k++;
                    }
                    //cout<<k<<' '<<j<<' '<<right[j]<<endl;
                    right[j]=min(right[j], k-j-1);


                    //printf("%d %d %d %d %d\n",i,j, height[j], left[j], right[j]);

                    ans=max(ans, height[j]*(left[j]+right[j]+1));
                }
                else {
                    height[j]=0;
                    left[j]=0x7fffffff;
                    right[j]=0x7fffffff;
                }
            }
        }
        return ans;
    }
};