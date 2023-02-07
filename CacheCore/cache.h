#pragma once
#include <string>
#include <memory>
#include "LRU.h"
#include "FIFO.h"
#include "LIFO.h"
constexpr auto MAX_CACHE_SIZE = 4096;
using namespace std;

enum EvictionPolicy
{
    LRU,
    LFU,
    FIFO,
    LIFO
};

class Cache;
typedef shared_ptr<Cache> CachePtr;

class Cache
{
public:
    Cache(int size = MAX_CACHE_SIZE);
    virtual string get(string key) = 0;
    virtual void put(string key, string value) = 0;
    virtual void deleteKey(string key) = 0;
    virtual void clear() = 0;
    virtual void printCache() = 0;
    static LRUCache<int> *getLRUCache(int size = MAX_CACHE_SIZE)
    {
        return new LRUCache<int>(size);
    };
    static FIFOCache<int> *getFIFOCache(int size = MAX_CACHE_SIZE)
    {
        return new FIFOCache<int>(size);
    };
    static LIFOCache<int> *getLIFOCache(int size = MAX_CACHE_SIZE)
    {
        return new LIFOCache<int>(size);
    };
    ~Cache();
};