show3Cliques(g,n):
   Input graph g of n vertices numbered 0..n-1

   for all i=0..n-3 do
      for all j=i+1..n-2 do
	 if i,j adjacent in g then
            for all k=j+1..n-1 do
               if i,k adjacent in g ∧ j,k adjacent in g then
	          print i"-"j"-"k
	       end if
	    end for
	  end if
      end for
   end for
   The following algorithm uses three nested loops to print all 3-cliques in order.
    Hence its asymptotic running time is O(n3). 