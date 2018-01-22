# Everything about graph

## Propeties

- E(most) = V/(V-1)/2 (complete graph)
- dense: E~V^2
- sparse: E~V
- adjacent: v to v
- incident: e to v
- degree of v

### Kinds of graph

- path
- cycle
- length of path or cycle
- tree (no cycle)
- spanning tree
- clique
- hamiltonian path/cycle
  - each vertex exactly once
- Euler path/cycle
  - each edge exactly once
  - a graph has a Euler path iff it has two vertices have odd degree
  - a graph has a Euler circuit iff all vertex have even degree

## Representations

### array of edges

- space efficient
- complex adding and deleting edges

```c
newGraph(V):
    input: number of vertex V
    output: new empty graph
    storage: O(E)
    cost: O(1)

    g.nV = V
    g.nE = 0
    g.edges[] memory allocation
    return g



InsertEdge(g, (v, w)):
    input: graph g, edge(v, w)
    cost: O(E)

    i = 0
    while i < g.nE && g.edges[i] != （v, w) do
        i ++
    end while

    if i = g.nE     // can not find (v, w)
        g.edge[i] = (v, w)
        g.nE++
    end if


removeEdge(g, (v,w)):
    input: graph g, edge(v,w)
    cost: O(E)

    i = 0
    while i < g.nE && g.edges[i] != (v,w) do
        i++
    end while
    if g < nE then
        g.edges[i] = g.edges[nE - 1] //replaced by last edge in the array
        g.nE--
    end if

show(g):
    input: graph g

    for all i = 0 to i = g.nE -1 do
        print g.edges[i]
    end for
```

### adjacency matrix

edges are represented by a V * V matrix

- advantage: easily implement
- disadvantage: memory-inefficient for sparse graph

```c
newGraph(V):
    input: number of vertex
    output: new empty graph
    storage cost: O(V*V)
    cost: O(V*V)

    g.nV = V
    g.nE = 0
    memory allocation for g.edges[][] V*V
    for all i,j = o to V-1 do 
        g.edges[i][j] = 0
    end for
    return g



insertEdge(g, (v, w)):
    input: graph g, edge(v, w)
    cost: O(1)

    if g.edges[v][w] = 0 then
        g.edges[v][w] = 1
        g.edge[w][v] =1
        g.nE++
    end if

removeEdge(g, (v, w)):
    input: graph g, edge(v,w)
    cost: O(1)

    if g.edge[v][w] = 1 then
        g.edge[v][w] = 0
        g.edge[w][v] = 0
        g.nE--
    end if

showGraph(g):
    input: graph g

    for all i = 0 to g.nE - 1 do 
        for all j = i + 1 to g.nE -1 do 
            if g.edge[i][j] = 1 then
                print i"-"j
            end if
        end for
    end for
```

### adjacency list

for each vertex, store linkedlist of adjacent vertex

- advantage: memory efficient if sparse
- disadvantage: has many possible representations

```c
newGraph(V):
    input: number of vertex
    output: new empty graph
    storage cost:
    cost: O(V+E)

    g.nV = V
    g.nE = 0
    memory allocation for g.edges[]
    for all i = 0 to g.nV - 1 do 
        g.edge[i] = NULL
    end for
    return h



insertEdge(g, (v, w)):
    input: graph g, edge(v, w)
    cost: O(E)  search in linked list

    if w is not in g.edge[v] then
        insert w into g.edge[v]
        insert v into g.edge[w]
        g.nE++
    end if



removeEdge(g, (v, w)):
    input: graph g, edge(v, w)
    cost: O(E) search in linked list

    if w in g.edge[v] then
        remove w into g.edge[v]
        remove v into g.edge[w]
        g.nE--
    end if
```

### compare

            |array of edges|adjacency matrix|adjacency list
------------|--------------|----------------|--------------
space       | E            | V*V            | V+E
------------|--------------|----------------|--------------
initialize  | 1            | V*V            | V
------------|--------------|----------------|--------------
insert      | E            | 1              | 1
------------|--------------|----------------|--------------
remove      | E            | 1              | E

## Graph Traversal

### depth-first search

```c
hasPath(g, src, dest):
    input: graph G, vertex s and d
    output: true if there is a path between s and d, false otherwise
    cost: O(V+E)

    return dfsPathCheck(g, src, dest)

dfsPathCheck(g, v, dest):
    mark v as visited
    for all (v, w) in edges(g) do
        if w = dest then
            return true
        end if
        if w has not been visited do
            if dfsPathCheck(g, w, dest) then
                return true
            end if
        end if
    end for
    return false



visited[]   //global array to store previously visited vertex
findPath(g, src, dest):
    input graph g, vertex src adn dest

    for all v in g do
        visited[v] = -1
    end for
    visited[src] = src
    if dfsPathCheck(g, src, dest) then
        v = dest
        while v != src do
            print v"-"
            v = visited[v]
        end while
        print src
    end if

dfsPathCheck(g, v, dest)
    input: Graph g, vertex v and dest

    for all (v, w) in edges(g) do
        if w = dest then
            visited[w] = v
            return true
        end if
        if visited[w] = -1 then
            visited[w] = v
            if dfsPathCheck(g, w, dest) then
                return true
            end if
        end if
    end for
    return false



visited[]
findPath(g, src, dest):
    input graph g, vertex src adn dest

    for all v in g do
        visited[v] = -1
    end for
    found = false
    visited[src] = src
    push src onto stack    
    while found == false do stack is not empty do
        pop stack to v
        if v = dest then
            found = true
        else 
            for each (v,w) in edges(g) do
                visited[w] = w
                push w onto stack
            end for
        end if
    end while
```

### breadth-first search

hard to implement recursively
can find the shortest path

```c
visited[]
bfsfindPah(g, src, dest)
    input: Graph g, vertex src and dest

    for all v in g do
        visited[v] = -1
    end for
    visited[src] = src
    enqueue src onto stack
    found = false

    while found == false && stack is not empty do
        dequeue stack to v
        if v = dest then
            found = true
        else
            for each (v, w) in edges(g) do
                visited[w] = v
                enqueue w onto stack
            end for
        end if
    end while
 ```

### cycle check

- it has a path > 1
- src = end
- without using any edge more than once

 ```c
hasCycle(g):
    input: Graph g
    output: true if there is a cycle, false otherwise

    // make sure to check all connected component
    mark all vertex as unvisited
    for each v in g do
        if v has not been visited then
            if dfsCycleCheck(g, v, v) then
                return true
            end if
        end if
    end for
    return false

dfsCycleCheck(g, curr, prev):
    mark curr as visited
    for each (curr, next) in edge(g) do
        if next has not been visited then
            return dfsCycleCheck(g, next, curr)
        else if next != prev then   // next is not previous one 
            return true
        end if
    end for
    return false
 ```

### Connected Components

```c
components(g):
    input graph g

    for all v in g do
        componentOf[v] = -1
    end for
    componentID = 0

    for all v in g do
        if componentOf[v] = -1 then
            dfsAssign(g, v, componentID)
        end if
        componentID++
    end for

    dfsAssign(g, v, ID):
        componentOf[v] = ID
        for (v,w) in edge(g) do
            if componentOf[w] = -1 then
                dfsAssign(g, w, ID)
            end if
        end for
```

### Hamiltonian

- keep track of path length

```c
cost: (V-1)!
visited[]
hasHamiltonianPath(g, src, dest):
    for all v in g do
        visited[v] = false
    end for
    return dfsHamiltonianCheck(g, src, dest, g.V - 1) then

dfsHamiltonianCheck(g, v, dest, d)：
    visited[v] = true
    if dest = v then
        if d = 0 then
            return true
        else
            visited[v] = false
            return false
        end if
    end if
    for each (v, w) in edge(g) do
        if visited[w] = false
            return dfsHamiltonianCheck(g, w, dest, d-1)
        end if
    end for
    visited[v] = false
    return false
```

### Euler Path

```c
hasEulerPath(g, src, dest)
    cost: O(V)

    for all v in g and v != src and v!= dest do // O(V)
        if degree(g, v) is odd then
            return false
        end if
    end for
    if src = dest then  // find Euler circuit
        if degree(g, src) is odd
            return false
    else                // find Euler path(not circuit)
        if degree(g, src) is even or degree(g, dest) is even
            return false
    end if
    return true
```
