/*
*思路是为每个bar找到左右两边小于当前bar的位置ln、rn，然后计算面积
*用栈作为辅助，每遇到比栈顶大的压栈，遇到小的则计算面积，当前高度为栈顶位子的高度，rn = i，ln是栈顶第二个位置的高度
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	int ans = 0;
    	stack<int> hi = stack<int>();
        heights.push_back(0);//加入哨兵为了可以计算最后一个bar
    	for(int i=0;i<heights.size();){
            if(hi.empty()||heights[i]>heights[hi.top()]){
                hi.push(i);
                i++;
            }else{
                int curhi = hi.top();//取当前高度的索引
                int curh = heights[curhi];
                hi.pop();
                //还需要考虑栈现在为空
                int ln = -1;
                if(!hi.empty()){
                    ln = hi.top();//一定小于当前的高度的左边索引,小于当前高度的右边索引是i
                }                
                int area = curh*(i-ln-1);//高的先计算，在向矮的扩展
                if(area>ans){
                    ans = area;
                }                
            }   		
    	}
    	return ans;
    }
};