/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = levelOrder(root);
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	int st =0,found = data.find(',');
    	TreeNode *root=NULL;
    	queue<TreeNode*> qu;
    	if(found!=string::npos){
    		string tmp = data.substr(st,found-st);
    		if(tmp!="null"){
    			root = new TreeNode(stringToInteger(tmp));
    			qu.push(root);
    		}
    		st = found+1;
    		found = data.find(',',st);
    	}
    	while(!qu.empty()){
    		TreeNode* cur = qu.front();
    		qu.pop();
    		if(found!=string::npos){
    			string tmp = data.substr(st,found-st);
    			if(tmp!="null"){
    				cur->left = new TreeNode(stringToInteger(tmp));
    				qu.push(cur->left);
    			}else
    				cur->left = NULL;
    			st = found+1;
    			found = data.find(',',st);
    			
    			if(found!=string::npos){//右边
    				string tmp = data.substr(st,found-st);
    				if(tmp!="null"){
    					cur->right = new TreeNode(stringToInteger(tmp));
	    				qu.push(cur->right);
    				}else
    					cur->right = NULL;
	    			st = found+1;
	    			found = data.find(',',st);
    			}else{
    				cur->right = NULL;
    			}
    		}else{
    			cur->left = NULL;
    			cur->right = NULL;
    		}
    	}
    	return root;	
    }
    //遍历
    string levelOrder(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
        	TreeNode* cur = q.front();
        	q.pop();
        	if(!cur)
        		ans.append("null,");
        	else{
        		ans.append(integerToString(cur->val));
        		ans.push_back(',');
	        	q.push(cur->left);
	        	q.push(cur->right);	        	
        	}
        }
        return ans;
    }  
    //整形和字符串的转换
    string integerToString(int n) {
		ostringstream stream;
		stream << n;
		return stream.str();
    }
    int stringToInteger(const string& str) {
		istringstream stream(str);
		int value;
		stream >> value;
		return value;
    }
    vector<string> split(string data){
    	vector<string> ans;
    	int st=0,found = data.find(',');
    	while(found!=string::npos){
    		string tmp = data.substr(st,found-st);
    		ans.push_back(tmp);
    		st = found+1;
    		found = data.find(',',st);
    	}
    	return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));