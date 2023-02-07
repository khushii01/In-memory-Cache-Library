#pragma once
#include <map>
#include <memory>
#include <unordered_map>
#include <iostream>
#include "cache.h"
#include "DoublyLinkedList.h"

template <typename T>
class LRUCache
{
    size_t capacity;
    std::unordered_map<int, DLLNode<T> *> cache_map;
    DLLNode<T> *head;
    DLLNode<T> *tail;

public:
    explicit LRUCache(size_t capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}

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
            moveToTail(cache_map[key]);
        }
    }

    T get(int key)
    {
        T value;
        // If key is not present in the cache
        if (cache_map.find(key) == cache_map.end())
            return 0;
        // If key is present in the cache return the value and move it to tail (Least recently used)
        else
        {
            value = cache_map[key]->value;
            moveToTail(cache_map[key]);
        }
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
    // Remove node from the list
    void removeNode(DLLNode<T> *node)
    {
        if (node->prev)
            node->prev->next = node->next;
        else // node is head
            head = node->next;
        if (node->next)
            node->next->prev = node->prev;
        else // node is tail
            tail = node->prev;
        delete node;
    };

    // Move node to the tail
    void moveToTail(DLLNode<T> *node)
    {
        if (node == tail)
            return;
        removeNode(node);
        addNode(node->key, node->value);
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