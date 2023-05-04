#include <iostream>
using namespace std;
#include<vector>
#include<stack>

int largestRectangleArea(vector<int>& heights) {
    vector<int> left(heights.size()), right(heights.size());
    stack<int> s;

    for (int i = 0; i < heights.size(); i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty()) {
        s.pop();
    }

    for (int i = heights.size() - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? heights.size() : s.top();
        s.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
        maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
    }

    return maxArea;
}

int main() {
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  cout << largestRectangleArea(heights);
}