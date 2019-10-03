// Runtime: 32 ms
// Memory Usage: 11.6 MB

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        if (m>n)
        {
            swap(nums1,nums2);
            swap(n,m);
        }
        int li=0,ri=m;
        int i,j,k,half=(m+n+1)/2;
        int maxleft,minright;
        while (li<=ri)
        {
            i=(li+ri)/2;
            j=half-i;
            if (i < m && nums2[j-1] > nums1[i])
                li = i + 1;
            else if (i > 0 && nums1[i-1] > nums2[j])
                ri = i - 1;
            else {
                if (i==0)
                    maxleft=nums2[j-1];
                else if (j==0)
                    maxleft=nums1[i-1];
                else 
                    maxleft=max(nums1[i-1],nums2[j-1]);
                
                if ((m+n)%2==1)
                    return maxleft;
                
                if (i==m)
                    minright=nums2[j];
                else if (j==n)
                    minright=nums1[i];
                else
                    minright=min(nums1[i],nums2[j]);
                
                return (double)(maxleft+minright)/2.0;
                    
            }
        }
        
        
    }
};