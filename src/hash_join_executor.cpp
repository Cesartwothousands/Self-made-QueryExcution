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
    if(arraynum < array.size()){
        *tuple = array[arraynum];
        arraynum++;
        return true;
    }
    
    Tuple t;
    while (right_ -> Next(&t)){

        ht.GetValue(hash_fn_->GetHash(t), &(this ->array));
        if (array.size()>0){
            *tuple = array[0];
            arraynum = 1;
            return true;
        }
    }
    
    return false;
}
