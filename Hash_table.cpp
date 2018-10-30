//
// Created by kosti on 10/20/2018.
//

#include "Hash_table.h"
#include "Value.h"
#include "utilities.h"

Hash_table::Hash_table( int buck, int dimension, int k, std::string func){
    this->k=k;
    this->d=dimension;
    this->hash_tb.rehash(buck);
    this->hash_tb.max_load_factor(10000);
    //if (func == "euclidean") {
        hfunc = new hash_func(dimension, k,func);
    //}
}
Hash_table::~Hash_table() {
    this->hash_tb.clear();
    this->hfunc->clean();
    this->hfunc=NULL;
}

void Hash_table::add_item(data_point<int>& k,int tb_size,std::vector<int> r){
    Key f;
    value_point<int> point = this->hfunc->hash_value(k,f.hash_val,this->k,tb_size,r);
    this->hash_tb.insert({f,point});
}

Key Hash_table::query_item(data_point<int>& k,int tb_size,std::vector<int> r){
    Key f;
    this->hfunc->hash_value(k,f.hash_val,this->k,tb_size,r);
    return f;
}

std::vector<int> get_hams(int num,int probes,int max){
    int h=1;
    std::vector<int> hams;
    for (int i=0;i<probes;i++){
        hams.push_back(h^num);
        h=h<<1;
        if (h>max) break;
    }
    return hams;
}

void Hash_table::get_bucket(data_point<int>& z,Key k, std::map<std::string,value_point<int>>& mp,std::vector<int> r,int probes ,int max_num){
    Key f;
    std::vector<int> hams = get_hams(k.hash_val,probes,max_num);
    hams.push_back(k.hash_val);
    Key temp;
    for (int i=0;i<hams.size();i++){
        temp.hash_val = hams[i];
        auto range=this->hash_tb.equal_range(temp);
        value_point<int> point = this->hfunc->hash_value(z,f.hash_val,this->k,max_num,r);
        for(auto it = range.first; it != range.second ; it++ ){
            mp.insert({it->second.p->name,it->second});
        }
    }
}

void Hash_table::print_stats(){
    std::cout << "Number of buckets: " << hash_tb.bucket_count() << std::endl;
    std::cout << "Number of  Max buckets: " << hash_tb.max_bucket_count() << std::endl;
    std::cout << "Hash table size: " << hash_tb.size() << std::endl;
    for (unsigned i=0; i<hash_tb.bucket_count(); i++) {
        std::cout << "bucket #" << i << " has " << hash_tb.bucket_size(i) << " elements.\n";
    }
}


