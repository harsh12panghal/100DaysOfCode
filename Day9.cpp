/*
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints 
of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.



*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maxi = 0;

        while(i<j){
            int mini = min(height[i], height[j]);
            int area = mini*(j-i);
            maxi = max(area, maxi);

            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxi;
    }
};
