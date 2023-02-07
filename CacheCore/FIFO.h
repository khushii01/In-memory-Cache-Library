#pragma once
#include <map>
#include <memory>
#include <unordered_map>
#include <iostream>
#include "cache.h"

template <typename T>
class FIFOCache
{
private:
    size_t capacity;
    std::unordered_map<int, DLLNode<T> *> cache_map;
    DLLNode<T> *head;
    DLLNode<T> *tail;

public:
    explicit FIFOCache(size_t capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}

    void put(int key, T value)
    {
        // If key is not present in the cache, add it to the cache
        if (cache_map.find(key) == cache_map.end())
        {
            // If cache is full, remove the head
            if (cache_map.size() == capacity)
            {
                cache_map.erase(head->key);
                removeHead();
            }
            // Add the new node to the tail
            cache_map[key] = addNode(key, value);
        }
        // If key is present in the cache, update the value and move it to tail (Least recently used)
        else
        {
            cache_map[key]->value = value;
        }
    }

    T get(int key)
    {
        if (cache_map.count(key) == 0)
        {
            return T();
        }
        DLLNode<T> *node = cache_map[key];
        T value = node->value;
        return value;
    }
    void printCache()
    {
        DLLNode<T> *node = head;
        while (node != nullptr)
        {
            std::cout << node->key << " " << node->value << "\n";
            node = node->next;
        }
    }

    // Add node to the tail
    DLLNode<T> *addNode(int key, T value)
    {
        DLLNode<T> *node = new DLLNode<T>(key, value);
        // Add node to the tail
        if (tail)
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        // Empty list
        else
        {
            head = node;
            tail = node;
        }
        return node;
    };
    // Remove head
    void removeHead()
    {
        DLLNode<T> *node = head;
        if (head)
        {
            head = head->next;
            if (head)
                head->prev = nullptr;
            // Only one node in the list
            else
                tail = nullptr;
        }
        delete node;
    };
};