class Solution:
    # https://leetcode.com/problems/path-sum/
    def dfs(self, root, targetSum):
        if(root.left == None and root.right == None):
            return targetSum == root.val
        answer = False
        if(root.left != None):
            answer = answer | self.dfs(root.left, targetSum - root.val)
        if(root.right != None):
            answer = answer | self.dfs(root.right, targetSum - root.val)
        return answer
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if(root == None):
            return False
        return self.dfs(root, targetSum)
        
