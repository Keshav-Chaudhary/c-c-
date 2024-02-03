/*Question 1: T(n) = 2T(n/2) + c

Solution: 

Step 1: Draw a recursive tree 
Recursion Tree
Recursion Tree

Step 2: Calculate the work done or cost at each level and count total no of levels in recursion tree 
Recursive Tree with each level cost
Recursive Tree with each level cost

Count the total number of levels – 

Choose the longest path from root node to leaf node

 n/20 -→ n/21 -→ n/22 -→ ……… -→ n/2k

Size of problem at last level = n/2k

 At last level size of problem becomes 1

 n/2k = 1

 2k = n

  k = log2(n)   

Total no of levels  in recursive tree = k +1 = log2(n) + 1

Step 3: Count total number of nodes in the last level and calculate cost of last level
 No. of nodes at level 0 = 20 = 1

  No. of nodes at level 1 = 21 = 2

 ………………………………………………………

 No. of nodes at level log2(n) = 2log2(n) = nlog2(2) = n

 Cost of sub problems at level log2(n) (last level) = nxT(1) = nx1 = n  

Step 4: Sum up the cost all the levels in recursive tree  
   T(n) = c + 2c + 4c + —- + (no. of levels-1) times + last level cost

 = c + 2c + 4c + —- + log2(n) times + Θ(n)

 = c(1 + 2 + 4 + —- + log2(n) times) + Θ(n)

 1 + 2 + 4 + —– + log2(n) times –> 20 + 21 + 22 + —– + log2(n) times –> Geometric Progression(G.P.)

= c(n) + Θ(n)

Thus, T(n) = Θ(n)*/