## 1

c   stack (top at left)
-   0
0   1
1   2 3 4
2   5 3 4
5   6 7 3 4
6   7 3 4
7   3 4
3   4
4   -


c   stack(top at left)
-   3
3   1 2 4 5
1   0 2 4 5
0   2 4 5
2   4 5
4   5
5   6 7
6   7
7   -


c   queue(front at left)
-   0
0   1
1   2 3 4
2   3 4 5
3   4 5
4   5
5   6 7
6   7
7   -


c   queue(front at left)
-   3
3   1 2 4 5
1   2 4 5 0
2   4 5 0
4   5 0
5   0 6 7
0   6 7
6   7
7   -

## 2

### Graph 1

Hamiltonian path    0-1-2
Euler path  0-1-2
hamiltonian circuit none
Euler circuit   none

### Graph 2

Hamiltonian path    0-1-2
Euler path      0-1-2
hamiltonian circuit 0-1-2-0
Euler circuit   0-1-2-0

### Graph 3

Hamiltonian path    none
Euler path  none
hamiltonian circuit none
Euler circuit   none

### Graph 4

Hamiltonian path    0-1-2-3
Euler path  none
hamiltonian circuit 0-1-2-3-0
Euler circuit   none

### b

vertix 2 and 5 have odd degree, so there is a Euler path, but no Euler circuit

2-3-0-1-


## 3

hasCycle(G):
|  Input  graph G
|  Output true if G has a cycle, false otherwise
|
|  mark all vertices as unvisited
|  for each vertex v∈G do           // make sure to check all connected components
|  |  if v has not been visited then
|  |     if dfsCycleCheck(G,v,v) then
|  |        return true
|  |     end if
|  |  end if
|  end for
|  return false

dfsCycleCheck(G,v,u):      // look for a cycle that does not go back directly to u
|  mark v as visited
|  for each (v,w)∈edges(G) do
|  |  if w has not been visited then
|  |     return dfsCycleCheck(G,w,v)
|  |  else if w≠u then
|  |     return true
|  |  end if
|  end for
|  return false