//11. Container With Most Water
//tag：Array ,Two Pointer
//问题描述：给定n个非负整数，根据数组元素大小绘制n垂直线。找到两条线和X轴组成一个容器,使容器包含最多的水。
//思路：从两头往中间扫，每次找两头最小的作为高度，i,j的距离作为宽度；然后高度小的一端向中间寻找高度比之大的
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for(int i=0,j=height.size()-1;i<j;){
            int area = 0,minheight;
            if(height[i]<=height[j]){//find first <hi
                minheight = height[i];
                area = (j-i)*minheight;
                if(area>ans)
                    ans = area;
                while(i+1<height.size()&&height[++i]<=minheight);//找到下一个比高度大的
            }else{
                minheight = height[j];
                area = (j-i)*minheight;
                if(area>ans)
                    ans = area;
                while(j-1>=0&&height[--j]<=minheight);
            }
        }
        return ans;
    }
};