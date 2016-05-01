/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-15-20.01
 */
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

struct Node
{
    int key,value;
    Node(int k,int v):key(k),value(v){}
};

class LRUCache
{
private:
    int max_size;
    list<Node> cacheList;
    unordered_map<int,list<Node>::iterator> mp;
public:
    LRUCache(int capacity) {max_size=capacity;}

    int get(int key)
    {
        if(mp.find(key)==mp.end()) // 未命中
            return -1;
        else
        {
            auto list_it=mp[key];
            Node node(key,list_it->value);
            cacheList.erase(list_it);
            cacheList.push_front(node);
            mp[key]=cacheList.begin();
            return node.value;
        }
    }

    void set(int key, int value)
    {
        auto it=mp.find(key);
        if(it==mp.end()) // 未命中
        {
            if(cacheList.size()>=max_size) // 驻留集已满
            {
                mp.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            Node node(key,value);
            cacheList.push_front(node);
            mp[key]=cacheList.begin();
        }
        else // 命中，将加入的结点置于链表头部，表示最近一次使用
        {
            cacheList.erase(mp[key]);
            Node node(key,value);
            cacheList.push_front(node);
            mp[key]=cacheList.begin();
        }
    }
};

int main()
{
    LRUCache cache(3);
    cache.set(1,1);
    cache.set(2,2);
    cache.set(3,3);
    cache.set(4,4);

    cout<<cache.get(4)<<endl;
    cout<<cache.get(3)<<endl;
    cout<<cache.get(2)<<endl;
    cout<<cache.get(1)<<endl;

    cache.set(5,5);

    cout<<cache.get(1)<<endl;
    cout<<cache.get(2)<<endl;
    cout<<cache.get(3)<<endl;
    cout<<cache.get(4)<<endl;
    cout<<cache.get(5)<<endl;

    return 0;
}
/*

*/
