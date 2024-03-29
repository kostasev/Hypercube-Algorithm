//
// Created by kosti on 10/20/2018.
//

#ifndef UNTITLED_HASH_TABLE_H
#define UNTITLED_HASH_TABLE_H
#include <unordered_map>
#include <random>
#include <iostream>
#include <map>
#include "Key.h"
#include "hash_func.h"
#include "data_point.h"
#include "Value.h"


class Hash_table {
private:
    int d;
    int k;
    hash_func *hfunc;
    std::unordered_multimap<Key,value_point<int>> hash_tb;
public:
    Hash_table(int, int, int, std::string);
    ~Hash_table();
    void add_item(data_point<int>&,int,std::vector<int>);
    void get_bucket(data_point<int>&,Key,std::map<std::string,value_point<int>>&,std::vector<int>,int,int);
    Key query_item(data_point<int>&,int,std::vector<int>);
    void print_stats();
};


#endif //UNTITLED_HASH_TABLE_H
