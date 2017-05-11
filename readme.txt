The actual tree
===============

    *Note : the numbers of the nodes are just from the order in which they are
    created.

    0 : Depth=0  Height=8 (i,j) = (0, 0), parent : -1
     1 : Depth=1  Height=7 (i,j) = (0, 1), parent : 0
      2 : Depth=2  Height=6 (i,j) = (0, 2), parent : 1
       3 : Depth=3  Height=5 (i,j) = (0, 3), parent : 2
        4 : Depth=4  Height=4 (i,j) = (0, 4), parent : 3
         5 : Depth=5  Height=3 (i,j) = (0, 5), parent : 4
          6 : Depth=6  Height=2 (i,j) = (0, 6), parent : 5
           7 : Depth=7  Height=1 (i,j) = (0, 7), parent : 6
            8 : Depth=8  Height=0 (i,j) = (0, 8), parent : 7
         14 : Depth=5  Height=3 (i,j) = (1, 5), parent : 4
          16 : Depth=6  Height=2 (i,j) = (1, 6), parent : 14
           17 : Depth=7  Height=1 (i,j) = (1, 7), parent : 16
            18 : Depth=8  Height=0 (i,j) = (1, 8), parent : 17
         15 : Depth=5  Height=0 (i,j) = (2, 5), parent : 4
       9 : Depth=3  Height=3 (i,j) = (3, 3), parent : 2
        11 : Depth=4  Height=2 (i,j) = (3, 4), parent : 9
         12 : Depth=5  Height=1 (i,j) = (3, 5), parent : 11
          13 : Depth=6  Height=0 (i,j) = (3, 6), parent : 12
       10 : Depth=3  Height=0 (i,j) = (4, 3), parent : 2

How the nodes are placed on a grid
==================================

    Each node is assigned an (i,j) on the grid, this is what it looks like:


     0   1   2   3   4   5   6   7   8
                        14  16  17  18
                        15
                 9  11  12  13
                10
