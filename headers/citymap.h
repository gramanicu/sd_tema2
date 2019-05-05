#ifndef HEADERS_CITYMAP_H_
#define HEADERS_CITYMAP_H_

#include <string>
#include "graph.h"

class Citymap {
   private:
    // NOTE - On this map, the intersections have names :)
    Graph<std::string> map;

   public:
    Citymap(u_int32_t size = MAX_DIM){};

    ~Citymap(){};

    void addIntersection(const std::string& name) { map.addNode(name); }

    void addStreet(const std::string& src, const std::string& dest) {
        map.addLink(src, dest);
    }

    void add2WayStreet(const std::string& src, const std::string& dest) {
        map.addLink2Way(src, dest);
    }

    void removeStreet(const std::string& src, const std::string& dest) {
        map.removeLink(src, dest);
    }

    void remove2WayStret(const std::string& src, const std::string& dest) {
        map.removeLink2Way(src, dest);
    }

    void switchWay(const std::string& src, const std::string& dest) {
        map.switchLinks(src, dest);
    }

    void printMap() { map.printMatrix(); }

    bool routeExist(const std::string& src, const std::string& dest) {
        if (src == dest) {
            return true;
        }

        if (map.dijkstra(src, dest) == -1) {
            return false;
        } else {
            return true;
        }
    }

    int32_t routeLength(const std::string& src, const std::string& dest) {
        if(src==dest) {
            return 0;
        }

        return map.dijkstra(src, dest);
    }
};

#endif  // HEADERS_CITYMAP_H_