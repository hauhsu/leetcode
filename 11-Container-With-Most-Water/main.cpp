#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, result = 0;
        int area, dist;
        while (left != right) {
            dist = right - left;
            if (height[left] < height[right]) {
                area = height[left]*dist;
                if (area > result) {
                    result = area;
                }
                left += 1;
            } else {
                area = height[right]*dist;
                if (area > result) {
                    result = area;
                }
                right -= 1;
            }
        }
        return result;
    }
};

int main()
{
	auto sol = Solution();
	vector<int> v = {1,8,6,2,5,4,8,3,7};
	std::cout << sol.maxArea(v) << std::endl;  // 49
}
