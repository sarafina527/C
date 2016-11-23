class Solution
{
  public:
    static int maxSum(TreeNode* root)
    {
    	int sum = 0,maxsum = INT_MAX;
        if(!root) return sum;
        std::stack<TreeNode*> s = std::stack<TreeNode*>();
        TreeNode* t = root;
        while(t||!s.empty()){
        	while(t){
        		s.push(t);
        		sum+=t->value;
        		if(!t->left&&!t->right){
        			if(sum>maxsum){
        				maxsum = sum;
        				sum = 0;
        			}
        			break;
        		}
        		t = t->left;
        	}
        	if(!s.empty()){//循环中每次出一个节点
        		t = s.top();
        		s.pop();
        		t = t->right;
        	}
        }

    }
};