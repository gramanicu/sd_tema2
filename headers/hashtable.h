#ifndef HEADERS_HASTABLE_H_
#define HEADERS_HASTABLE_H_

#include <iostream>
#include <list>
#include <vector>
#include <utility>

#define MAX_SIZE 15000

// Key, Value
template<typename K, typename V> 
class Hashtable {
    private:
        std::vector<std::list<std::pair<K,V>>> map;
        u_int32_t allocatedSize;

        u_int32_t Hash(const K& key) const{
            std::hash<K> hasher;
            size_t hash = hasher(key);
            int32_t finalHash = static_cast<int32_t>(hash);
            return finalHash % allocatedSize;
        }
        
    public:
        u_int32_t size;

        Hashtable(u_int32_t mapSize = MAX_SIZE): map(mapSize), allocatedSize(mapSize), size(0) {};
        ~Hashtable() {};
        Hashtable(const Hashtable& other) {
            map = other.map;
            allocatedSize = other.allocatedSize;
            size = other.size;
        }

        void Insert(const K& key, const V& value) {
            u_int32_t index = Hash(key);
            map.at(index).push_back(std::make_pair(key, value));
            size++;
        }

        V Search(const K& key) const{
            u_int32_t index = Hash(key);
            for(auto& i : map.at(index)) {
                if(i.first == key) {
                    return i.second;
                }
            }

            return -1;
        }

        void Delete (K key) {

        }
};

#endif  // HEADERS_HASTABLE_H_