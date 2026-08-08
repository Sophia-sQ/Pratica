import collections

def get_shortest_path_bfs(graph, source, destination):
    # Setup tracking data structures
    queue = collections.deque([source])
    visited = {source}
    parent = {}
    
    # Standard BFS
    while queue:
        current = queue.popleft()
        
        if current == destination:
            break
            
        for neighbor in graph[current]:
            if neighbor not in visited:
                visited.add(neighbor)
                parent[neighbor] = current  # Record the edge used
                queue.append(neighbor)
                
    # Path Reconstruction (Backtracking)
    if destination not in visited:
        return None # No path exists
        
    path = []
    current_node = destination
    while current_node is not None:
        path.append(current_node)
        current_node = parent.get(current_node) # Move to the parent
    print(parent)
    return path[::-1] # Reverse it to get source -> destination

# Example Graph
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

print(get_shortest_path_bfs(graph, 'A', 'F')) 
# Output: ['A', 'C', 'F']
