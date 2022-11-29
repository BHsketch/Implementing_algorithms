# Implementing Dijkstra's algorithm
Dijkstra's algorithm helps find the shortest path through a weighted graph.
we start by having a table that has columns for the node, its parent node and its current least 'cost'(i.e the least cost out of all the paths we have checked till now)

## General algorithm:
1. we start from the base node and update the table for all the neighbours of the base node.
2. We pick the node (lets say the name of the node is A)with the least cost(lets say it has a cost 'c') in the table and traverse through all its neighbours.
3. For each neighbour, its cost will be some c'=(c+ their weight from the node A). 
4. if c' is lesser than that neighbours current cost in the table, that means we have found a shorter path to it. So we update the table with a new cost and a new parent node.
5. Repeat for the remaining neighbours
6. repeat steps 2 to 5 for all nodes in the table.
7. After this has been done for all nodes, the final cost for the end node in the table is the least possible cost to it.
8. We can then back-track the parent nodes(by looking at the parent column in the table) to figure out the entire path taken to get the least cost.

### Q)How do we know that by the time we check a node(the one with the least cost in the table) its cost in the table is the least possible cost for that node? Because we haven't checked the 
whole graph yet, so if we find some other path to this node that is cheaper, it will have repurcussions throughout the table!!
Ans)lets say that the node we are checking has a name B and a cost = k i.e. at this moment, out of all the nodes that still haven't been checked, B has the least cost of k. This means that 
every node that hasn't been checked has a cost >k. So they ANYWAYS wouldn't give me a shorter path to B!! since it takes more than B's current price to get to those nodes in the first place!

### but then another question bubbles up: how do we know the nodes with prices 0 ->k-1 have been checked properly?
Ans: we can make the following statement: if all the nodes before k have been checked correctly, I can be sure that k is in fact the lowest price for the node corresponding to it.
//ly, if all the nodes before k-1 have been checked correctly, I can be sure that k-1 is in fact the lowest proce for the node corresponding to it
.
.
.
.
if the node with price 0 has been checked correctly, I can be sure that 1 is in fact the lowest price for the node corresponding to it
And THAT we can be sure of because there is literally gonna be only one path with a zero price!! So that has to be the lowest

so we can be sure that by the time we check a node, its price in the table is the best way to get to it

## Using a priority queue to implement Dijkstra's algorithm:
The algorithm has to be modified slightly for this. The changes required are as follows:
1. Along with the cost table, we need to have a separate priority queue to store the cost of each neighbour.
2. Instead of modifying the table everytime we find a smaller cost for something, we will only enter final costs in the table.
3. Since we know that whenever we select the node with the smallest cost, (so that we can check its neighbours), its current cost <i>is</i> the final cost, we will add nodes to the table only when we select them
### The algorithm:
1.  