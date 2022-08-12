# Implementing Algorithms in c++ and python

## Breath first search:
### problem used:
(Refer to the book Grokking algorithms)
There is a network of friends, of which one friend (you) is looking for a mango seller to buy mangoes from. We assume that the person whose name starts with the letter 'm' is a mango seller. The code finds the mango seller using something called the breath-first search method to search the graph.

#### the basic algorithm: 
We maintain a stack that initially contains all the nearest neighbours.
Then we iterate through the stack.
If the neighbour is a mangoseller, we're done.
If the neighbour is not a mangoseller, we add that person's neighbours to the end of the current stack of people to be searched
we keep doing this until we find a mangoseller, and output no mango seller if we find none.

problem: this code is not corrected for loops in the graph(if the graph is bidirectional)
to solve this we need to, before checking anyone, make sure we haven't checked them before.
So this algorithm may be coupled with a search algorithm

## Dijkstra's algorithm in c++:
Dijkstra's algorithm is used to find the shortest path in a weighted, unidirectional graph.

### problem:
for problem refer to the book Grokking Algorithms
A graph is given as shown in the code. A person has a book, and wants to barter his way into owning a piano through bartering objects with multiple people(the nodes), where in each barter he loses a certain amount of money(the weight)
we need to find a way so that he can own a piano with the least amount of money lost

### the basic algorithm:
Initialize a "cost" table with infinity as the cost for each node(cost is the total money spent in getting to that node)
set a variable min as the first node's cost
find the node having cost = min by traversing all costs
For this node, traverse neighbours
for each neighbour, add weight to cost (totalcost =  cost of current node + its weight from the current node ) and compare totalcost with the neighbours cost as currently stored in the table.
If totalcost is lesser, we have found a cheaper way of getting to this node(the neighbous) so we update its cost to totalcost and parent node to the current node in the table
we keep doing this until all nodes have been tranversed
we now have the least cost for all nodes
we can find the path by backtracking the parent nodes

## Quicksort
### Basic algorithm (using recursion)
We have a list of numbers (nums)
if the list size is 0 or 1, return list
else, 
we select a random number as a pivot
create two new lists lesser and greater
we traverse the list
if the number< pivot we append it to lesser, else we append it to greater
we call quicksort for lesser and greater lists
concatinate quicksort(lesser), pivot, and quicksort(greater)
