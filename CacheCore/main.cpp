#include <iostream>
#include "cache.h"
using namespace std;

int main()
{
    // LRU Cache
    cout << "LRU Cache" << endl;
    auto *LRUcache = Cache::getLRUCache(3);
    LRUcache->put(1, 1);
    LRUcache->put(2, 2);
    LRUcache->put(3, 3);
    LRUcache->get(2);
    LRUcache->put(4, 4);
    LRUcache->get(3);
    LRUcache->put(5, 5);
    LRUcache->put(6, 6);
    LRUcache->printCache();

    // FIFO Cache
    cout << "FIFO Cache" << endl;
    auto *FIFOcache = Cache::getFIFOCache(3);
    FIFOcache->put(1, 1);
    FIFOcache->put(2, 2);
    FIFOcache->put(3, 3);
    FIFOcache->get(2);
    FIFOcache->put(4, 4);
    FIFOcache->get(3);
    FIFOcache->put(5, 5);
    FIFOcache->put(6, 6);
    FIFOcache->printCache();

    // LIFO Cache
    cout << "LIFO Cache" << endl;
    auto *LIFOcache = Cache::getLIFOCache(3);
    LIFOcache->put(1, 1);
    LIFOcache->put(2, 2);
    LIFOcache->put(3, 3);
    LIFOcache->get(2);
    LIFOcache->put(4, 4);
    LIFOcache->get(3);
    LIFOcache->put(5, 5);
    LIFOcache->put(6, 6);
    LIFOcache->printCache();

    return 0;
}