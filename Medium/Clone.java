/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    Node[] visited = new Node[105];
    public Node dfs(Node n) {
        if (n == null)
            return null;
        if (visited[n.val] != null)
            return visited[n.val];
        Node copy = new Node(n.val);
        visited[n.val] = copy;
        if (n.neighbors == null)
            return copy;
        for (Node neighbor : n.neighbors) {
            Node t = dfs(neighbor);
            copy.neighbors.add(visited[neighbor.val]);
            
        }
        return copy;
    }
    public Node cloneGraph(Node node) {
        return dfs(node);
    }
}
