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
        string post;
        postorder(root,post);
        return post;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      int found = data.find(' '),start = 0;
      vector<int> post;
      while(found!=string::npos){
        string tmp = data.substr(start,found-start);
        post.push_back(stringToInteger(tmp));
        start = found+1;
        found = data.find(' ',start);
      }
      vector<int> inorder = post;
      sort(inorder.begin(),inorder.end());//中序是排序后的序列
      return buildTree(inorder,post); 
    }

    void postorder(TreeNode* root,string& post){//后续遍历
      if(!root) return;
      postorder(root->left,post);
      postorder(root->right,post);
      post.append(integerToString(root->val));
      post.push_back(' ');//加分隔
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& post) {//根据中序和后序构造二叉树
      TreeNode* root =  buildTreei(inorder,post,0,0,post.size());   
      return root;
    }
    TreeNode* buildTreei(vector<int>& inorder, vector<int>& post,int ip,int pp,int size) {
      if(size<1) return NULL;
      int rootkey = post[pp+size-1];
      TreeNode* root = new TreeNode(rootkey);
      if(size==1) return root;  
      int i;
      for(i=ip;i<ip+size&&inorder[i]!=rootkey;i++);//在中序序列中找到根，根据根所在位置，分割左右子树序列
      root->left = buildTreei(inorder,post,ip,pp,i-ip);
      root->right = buildTreei(inorder,post,i+1,pp-ip+i,ip+size-i-1);//根据最后来倒推右子树的开始下标
      return root;
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
    void printv(vector<int> v){
      for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
      cout<<endl;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));