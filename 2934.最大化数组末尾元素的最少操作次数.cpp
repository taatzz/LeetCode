#include <vector>

using namespace std;

class Solution {
public:
    int find(vector<int>& n1, vector<int>& n2, int a, int b)
    {    
        int n = n1.size(), m = n2.size();
        
        int res = 0;
        for(int i = 0; i + 1< n; i++)
        {
            if(n1[i] > a || n2[i] > b)
            {
                if(n1[i] > b || n2[i] > a)
                    return n + 1;
                res++;
            }       
        }

        return res;
    }

    // 因为是只能两个数组的同位置进行交换，所以就分两种情况讨论。
    // 1.交换两个数组的最后一个元素
    // 2.不交换最后一个元素
    // 然后遍历数组如果遇到大于末尾的元素只能进行交换，如果交换之后还是不符合则这种情况不符合，返回n+1，否则返回交换的次数
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int n1 = find(nums1, nums2, nums1[n - 1], nums2[m - 1]);
        int n2 = find(nums1, nums2, nums2[m - 1], nums1[n - 1]) + 1;

        int res = min(n1, n2);
        return res >= n ? -1 : res;
    }
};