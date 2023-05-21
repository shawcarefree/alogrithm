static bool isSum = false;
class Solution {
public:
    void process(TreeNode* x,int curSum,int sum)
    {
        if(x->left == nullptr && x->right == nullptr)
        {
            //比较当前路劲和是否满足预期和
            if(x->val + curSum == sum)
            {
                isSum = true;
            }
            return;
        }
        
        //非叶节点，继续递归求和
        curSum += x->val;
        if(x->left != nullptr)
        {
            process(x->left,curSum,sum);
        }
        
        if(x->right != nullptr)
        {
            process(x->right,curSum,sum);
        }
    }
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
        {
            return false;
        }
        
        isSum = false;
        
        process(root,0,targetSum);
        
        return isSum;
    }
};