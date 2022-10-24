class Solution:
    def dfs(self, root):
        #return (largest path including forward, largest path not including foward)
        leftdfs = (0, 0)
        rightdfs = (0, 0)
        leftb = False
        rightb = False
        if root.left is not None:
            leftdfs = self.dfs(root.left)
            leftb = True
        if root.right is not None:
            rightdfs = self.dfs(root.right)
            rightb = True
        if leftb == False and rightb == False:
            return (root.val, root.val)
        if leftb == False:
            return (max(rightdfs[0], 0) + root.val, max(rightdfs[1], max(rightdfs[0], 0) + root.val))
        if rightb == False:
            return (max(leftdfs[0], 0) + root.val, max(leftdfs[1], max(leftdfs[0], 0) + root.val))
        first_condition = max(max(leftdfs[0], rightdfs[0]), 0) + root.val
        second_condition = max(max(leftdfs[1], rightdfs[1]), max(leftdfs[0], 0) + max(rightdfs[0], 0) + root.val)
        return (first_condition, second_condition)
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        return max(self.dfs(root)[0], self.dfs(root)[1])
