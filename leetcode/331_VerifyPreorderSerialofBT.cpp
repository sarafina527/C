//331. Verify Preorder Serialization of a Binary Tree
//tag： stack
//问题描述：判断类似leetcode树串行化表示的先序序列是否是有效的二叉树（不构造）
//思路: 1.用栈保存每个节点的是否有左右子树，用栈模拟深度DFS
//		2.当某个节点的左右子树齐全时出栈，
//		3.当栈空了且字符串遍历结束时返回true
class Solution {
public:
    bool isValidSerialization(string preorder) {
    	if(preorder.size()==0) return true;
    	if(preorder[0]=='#'){
    	    if(preorder.size()>1) return false;
    	    else return true;
    	}
        vector<pair<bool,bool> > lrlabel;
        preorder.push_back(',');//加入哨兵，以便最后一个能进入循环
        int stpos = preorder.find(',')+1,found = preorder.find(',',stpos);
        lrlabel.push_back(make_pair(0,0));//压入根
        while(found!=string::npos){
        	char cur = preorder[found-1];
        	while(!lrlabel.empty()&&lrlabel.back().first&&lrlabel.back().second){//左右孩子齐全则该子树OK
    			lrlabel.pop_back();
    		}
        	if(lrlabel.empty()){
        		return false;
        	}else{
        		if(!lrlabel.back().first){//当前结点的父亲没有左孩子则当前结点是其左孩子
        			lrlabel[lrlabel.size()-1].first = 1;
        			if(cur!='#'){//当左孩子是空，则不压栈，并置已有左孩子
        				lrlabel.push_back(make_pair(0,0));
        			}
        		}else{//已有左孩子,cur是右孩子
        			lrlabel[lrlabel.size()-1].second = 1;//标记parent已有右孩子
        			if(cur!='#'){//当右孩子空，当前子树OK，pop
        				 lrlabel.push_back(make_pair(0,0));
        			}
        		}
        	}
        	stpos = found+1;
        	found = preorder.find(',',stpos);
        }
        while(!lrlabel.empty()&&lrlabel.back().first&&lrlabel.back().second){//左右孩子齐全则该子树OK
			lrlabel.pop_back();
		}
        if(lrlabel.empty())
        	return true;
        else 
        	return false;
    }
};