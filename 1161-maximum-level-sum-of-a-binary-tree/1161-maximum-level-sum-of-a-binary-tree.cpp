// C-array implement queue
TreeNode* q[100000];// queue for TreeNode*
int front=0, back=0;
class Solution {
public:
    static int maxLevelSum(TreeNode* root) {
        int idx=0, sum=INT_MIN;
        front=back=0;// reset q
        q[back++]=root;// push
        int level=1;
        for( ; front<back; level++){
            int qz=back-front;
            int curSum=0;
            for (int i=0; i<qz; i++) {
                TreeNode* Node=q[front++];// pop
                curSum+=Node->val;
                if (Node->left) q[back++]=Node->left;// push
                if (Node->right) q[back++]=Node->right;// push
            }
            if(curSum>sum) idx=level, sum=curSum;
        } 
        return idx;
    }
};