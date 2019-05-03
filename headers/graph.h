#ifndef HEADERS_GRAPH_H_
#define HEADERS_GRAPH_H_

#include <iostream>
#include <queue>
#include <vector>

// Default maximum number of nodes
#define MAX_DIM 500

template <typename T>
class Graph {
   private:
    // The matrix of nodes
    std::vector<std::vector<int8_t>> matrix;

    // Link between id's and names
    std::vector<T> nodes;

    // Gets the ID
    // !!! ATTENTION - the nodes must be sorted !!!
    int getId(const T& data) const {
        int index = -1;
        for (auto& i : nodes) {
            index++;
            if (i == data) {
                return index;
            }

            if (i > data) {
                return -1;
            }
        }
        return -1;
    }

   public:
    // Constructor - initializes the matrix with 0's
    //             - also adds 1's on the main diagonal
    Graph(u_int32_t size = MAX_DIM)
        : matrix(size, std::vector<int8_t>(size, 0)) {
        for (u_int32_t i = 0; i < size; i++) {
            matrix[i][i] = 1;
        }
    };

    // Destructor
    ~Graph(){};

    // Copy-Constructor
    Graph(const Graph& other) {
        this->matrix = other.matrix;
        this->nodes = other.nodes;
    }

    // Add a new node
    void addNode(const T& data) { nodes.push_back(data); }

    // Link two nodes
    void addLink(const T& src, const T& dest) {
        int id1 = getId(src);
        if (id1 == -1) return;

        int id2 = getId(dest);
        if (id2 == -1) return;

        matrix[id1][id2] = 1;
    }

    // Link two nodes both ways
    void addLink2Way(const T& src, const T& dest) {
        int id1 = getId(src);
        if (id1 == -1) return;

        int id2 = getId(dest);
        if (id2 == -1) return;

        matrix[id1][id2] = 1;
        matrix[id2][id1] = 1;
    }

    // Removes the link from two nodes
    void removeLink(const T& src, const T& dest) {
        int id1 = getId(src);
        if (id1 == -1) return;

        int id2 = getId(dest);
        if (id2 == -1) return;

        matrix[id1][id2] = 0;
    }

    // Removes all links from two nodes
    void removeLink2Way(const T& src, const T& dest) {
        int id1 = getId(src);
        if (id1 == -1) return;

        int id2 = getId(dest);
        if (id2 == -1) return;

        matrix[id1][id2] = 0;
        matrix[id2][id1] = 0;
    }

    // Switches the links between nodes
    void switchLinks(const T& src, const T& dest) {
        int id1 = getId(src);
        if (id1 == -1) return;

        int id2 = getId(dest);
        if (id2 == -1) return;

        int8_t aux = matrix[id1][id2];
        matrix[id1][id2] = matrix[id2][id1];
        matrix[id2][id1] = aux;
    }

    // Find the length of the shortest path between two nodes
    // The algorithm is described in README
    int32_t dijkstra(const T& src, const T& dest) {
        if (src == dest) return 0;

        int sId = getId(src);
        if (sId == -1) return -1;

        int dId = getId(dest);
        if (dId == -1) return -1;

        std::vector<bool> visited;
        std::queue<int32_t> q;
        std::vector<int32_t> dist;
        std::vector<int32_t> parent;

        for (uint32_t i = 0; i < nodes.size(); i++) {
            visited.push_back(false);
            dist.push_back(MAX_DIM);
            parent.push_back(-1);
        }

        q.push(sId);
        visited[sId] = true;
        dist[sId] = 0;

        while (q.size()) {
            for (uint32_t i = 0; i < nodes.size(); i++) {
                // If it is a neighbour
                if (matrix[q.front()][i] == 1 && int32_t(i) != q.front()) {
                    if (visited[i] == false) {
                        visited[i] = true;
                        q.push(i);

                        dist[i] = dist[q.front()] + 1;
                        parent[i] = q.front();
                    } else {
                        if (dist[parent[i]] == dist[q.front()]) {
                            dist[i] = dist[q.front()] + 1;
                            parent[i] = q.front();
                        }
                    }
                }
            }

            q.pop();
        }

        if (dist[dId] == MAX_DIM) {
            return -1;
        } else {
            return dist[dId];
        }
    }

    // Print the adjacency matrix
    void printMatrix() const {
        for (u_int32_t i = 0; i < nodes.size(); i++) {
            for (u_int32_t j = 0; j < nodes.size(); j++) {
                std::cout << static_cast<int>(matrix[i][j]) << " ";
            }
            std::cout << "\n";
        }
    }
};

#endif  // HEADERS_GRAPH_H_