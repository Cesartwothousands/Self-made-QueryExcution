#include "../include/hash_join_executor.h"

HashJoinExecutor::HashJoinExecutor(AbstractExecutor *left_child_executor,
                                   AbstractExecutor *right_child_executor,
                                   SimpleHashFunction *hash_fn)
    : left_(left_child_executor),
      right_(right_child_executor),
      hash_fn_(hash_fn) {}

void HashJoinExecutor::Init(){
    left_ -> Init();
    right_ -> Init();
    Tuple tuple;

    while (left_ -> Next(&tuple)){
        hash_t Value = hash_fn_ -> GetHash(tuple);
        ht.Insert(Value, tuple);
    }
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
