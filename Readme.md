# Uber - 2nd Data Structures Homework

The most important data structure used to solve this homework is a generic Graph. It is implemented using an adjacency matrix. Also, every node has an index, and another templated value. For this problem (as it was implemented in the wrapper class "Citymap"), the other value was the name of an intersection. The graph has implemented simple operations to link nodes, remove the link, switch the direction of the link, etc.. But, one essential method implemented is dijkstra. This is a pathfinding algorithm.

## Disktra
My implementation was based on this steps, which describe the algorithm (on the [wikepedia page](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm))

- Mark all nodes unvisited. Create a set of all the unvisited nodes called the unvisited set.
- Assign to every node a tentative distance value: set it to zero for our initial node and to infinity for all other nodes. Set the initial node as current.
- For the current node, consider all of its unvisited neighbours and calculate their tentative distances through the current node. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one. For example, if the current node A is marked with a distance of 6, and the edge connecting it with a neighbour B has length 2, then the distance to B through A will be 6 + 2 = 8. If B was previously marked with a distance greater than 8 then change it to 8. Otherwise, keep the current value.
- When we are done considering all of the unvisited neighbours of the current node, mark the current node as visited and remove it from the unvisited set. A visited node will never be checked again.
- If the destination node has been marked visited (when planning a route between two specific nodes) or if the smallest tentative distance among the nodes in the unvisited set is infinity (when planning a complete traversal; occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The algorithm has finished.
- Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.

The algorithm will determine the shortest way and it's length.

## Notes

- I didn't implement any of my methods in .cpp files because I found that is almost impossible to do so with generic classes. Also, where the class wasn't generic (the wrapper, "Citymap"), the methods were very short (one-liners).

© 2019 Grama Nicolae, 312CA