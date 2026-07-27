Strongly connected component (Tarjans's Algo)

Difficulty: Hard

You are given a directed graph with V vertices labeled from 0 to V -1. The graph is represented by an adjacency list adj, where adj[u] contains a list of all vertices v such that there is a directed edge from vertex u to vertex v.

Find all strongly connected components (SCCs) in the graph. A strongly connected component is a maximal set of vertices such that every vertex in the set is reachable from every other vertex in the same set.

Note: Return all strongly connected components (SCCs) as a list of lists, where each inner list represents one component. The vertices within each component should be sorted in ascending order, and the complete list of components should be sorted in lexicographical order before returning the result.

Examples:

Input: V = 6, adj[][] = [[1], [2], [0, 3], [4], [3, 5], []]
Output: [[0, 1, 2], [3, 4], [5]]
Explanation:
  
As shown in the graph, there are three strongly connected components: [0, 1, 2], [3, 4], and [5]. After sorting the vertices within each component and arranging the list of components in lexicographical order, the final output becomes [[0, 1, 2], [3, 4], [5]].
Input: V = 3, adj[][] = [[1], [2], [0]]
Output: [[0, 1, 2]]
Explanation:
   

All of the nodes are connected to each other. So, there's only one SCC as shown.
Constraints:
1 ≤ V ≤ 105
1 ≤ E  ≤ 105, E number of edges in graph.
0 ≤ U, V ≤ V-1, U and V are vertices in the graph.

