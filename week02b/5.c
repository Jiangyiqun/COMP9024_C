// L[i].x denotes the first component (the index) of a pair L[i],
// L[i].v denotes its second component (the value). 

VectorSum(L1,L2):
   Input:  compact forms L1 of length m and L2 of length n
   Output: compact form of L1+L2

   i=0, j=0, k=0
   while i≤m-1 ∧ j≤n-1 do           // i is the index of L1, j is the index of L2
      if L1[i].x=L2[j].x then       // if index in L1[i] and L2[j] is equal, then add them up and put it into L3[k]
        if L1[i].v≠-L2[j].v then   
            L3[k]=(L1[i].x, L1[i].v+L2[j].v)
            i=i+1, j=j+1, k=k+1
        else
            // if L1[i].value + L2[j].value = 0 ,then no need to add to L3
            i=i+1, j=j+1
        end if
      else if L1[i].x<L2[j].x then  //if index in L1[i] is smaller, then copy L1[i] to L3[k]
         L3[k]=(L1[i].x,L1[i].v)
         i=i+1, k=k+1
      else
         L3[k]=(L2[j].x,L2[j].v)    // if index in L2[i] is smaller, then copy L2[i] to L3[k]
         j=j+1, k=k+1
      end if
   end while

    // either L1 or L2 will exausted, this mean only one while loop following will be excuted 
   while i<m-1 do                  // copy the remaining pairs of L1, if any
      L3[k]=(L1[i].x,L1[i].v)
      i=i+1, k=k+1
   end while   

   while j<n-1 do                  // copy the remaining pairs of L2, if any
      L3[k]=(L2[j].x,L2[j].v)
      j=j+1, k=k+1
   end while

   //Time complexity analysis: Adding a pair to L3 takes O(1) time. 
   //At most m+n pairs from L1 and L2 are added. Therefore, the time complexity is O(m+n).