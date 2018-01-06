## DFS

```c
hasPath(G,src,dest):
|  Input  graph G, vertices src,dest
|  Output true if there is a path from src to dest in G,
|         false otherwise
|
|  return dfsPathCheck(G,src,dest)

dfsPathCheck(G,v,dest):
|  mark v as visited
|  for all (v,w)∈edges(G) do
|  |  if w=dest then       // found edge to dest
|  |     return true
|  |  else if w has not been visited then
|  |     if dfsPathCheck(G,w,dest) then
|  |        return true    // found path via w to dest
|  |     end if
|  |  end if
|  end for
|  return false            // no path from v to dest
```

## BFS

```c
visited[] // array of visiting orders, indexed by vertex 0..nV-1

findPathBFS(G,src,dest):
|  Input  graph G, vertices src,dest
|
|  for all vertices v∈G do
|     visited[v]=-1
|  end for
|  found=false
|  visited[src]=src
|  enqueue src into new queue q
|  while found ∧ q is not empty do
|  |  dequeue v from q
|  |  if v=dest then
|  |     found=true
|  |  else
|  |  |  for each (v,w)∈edges(G) such that visited[w]=-1 do
|  |  |     visited[w]=v
|  |  |     enqueue w into q
|  |  |  end for
|  |  end if
|  end while
|  if found then
|     display path in dest..src order
|  end if
```
