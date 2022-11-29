#include "../include/hash_join_executor.h"

HashJoinExecutor::HashJoinExecutor(AbstractExecutor *left_child_executor,
                                   AbstractExecutor *right_child_executor,
                                   SimpleHashFunction *hash_fn)
    : left_(left_child_executor),
      right_(right_child_executor),
      hash_fn_(hash_fn) {}

void HashJoinExecutor::Init(){
    left_ -> Init();
    Tuple t;

    while (left_ -> Next(&t)){
        hash_t Value = hash_fn_ -> GetHash(t);
        ht.Insert(Value, t);
    }
    right_ -> Init();

    if (array.empty()){
        Tuple right_tuple;
        while (right_->Next(&right_tuple)){
            std::vector<Tuple> Value1;
            ht.GetValue(hash_fn_->GetHash(right_tuple), &Value1);
            for (const Tuple& left_iter : Value1){
                array.emplace_back(left_iter);
            }
        }
    }
    iter_ = array.begin();
};

bool HashJoinExecutor::Next(Tuple *tuple) {
    if (iter_ != array.end()) {
        const Tuple &curr_tuple = *iter_;
        *tuple = Tuple(curr_tuple);
        ++iter_;
        return true;
    }
    return false;
}
