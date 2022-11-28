#include "../include/hash_join_executor.h"

HashJoinExecutor::HashJoinExecutor(AbstractExecutor *left_child_executor,
                                   AbstractExecutor *right_child_executor,
                                   SimpleHashFunction *hash_fn)
    : left_(left_child_executor),
      right_(right_child_executor),
      hash_fn_(hash_fn) {}

void HashJoinExecutor::Init(){
    left_ -> Init();
    Tuple left_tuple;

    while (left_ -> Next(&left_tuple)){
        hash_t Value = hash_fn_ -> GetHash(left_tuple);
        ht.Insert(Value, left_tuple);
    }
    right_ -> Init();
};

bool HashJoinExecutor::Next(Tuple *tuple) {
    while (right_ -> Next(tuple)){
        Tuple right_tuple = *tuple;

        auto *vi = new std::vector<Tuple>();
        
        ht.GetValue(hash_fn_->GetHash(right_tuple), vi);
        if (!vi->empty()){
            delete vi;
            return true;
        }
    }
    
    return false;
}
