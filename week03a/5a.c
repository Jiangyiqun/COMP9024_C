
MinMaxDegree(g,n):
   Input  graph g of n vertices
   Output minimum and maximum vertex degree in g

   min=n-1, max=0
   for all vertices v∈g do
      deg[v]=0
      for all vertices w∈g, v≠w do
        if v,w adjacent in g then
	        deg[v]=deg[v]+1
	    end if
      end for
      if deg[v]<min then
	 min=deg[v]
      end if
      if deg[v]>max then
	 max=deg[v]
      end if
   end for
   return min,max

   The following algorithm uses two nested loops to compute the degree of each vertex.
    Hence its asymptotic running time is O(n2). 