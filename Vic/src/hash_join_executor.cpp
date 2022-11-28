#include "../include/hash_join_executor.h"

HashJoinExecutor::HashJoinExecutor(AbstractExecutor *left_child_executor, AbstractExecutor *right_child_executor,  SimpleHashFunction *hash_fn)
        : left_(left_child_executor), right_(right_child_executor), hash_fn_(hash_fn) {}

void HashJoinExecutor::Init() {
    left_->Init();
    Tuple left_tuple;
    while (left_->Next(&left_tuple)) {
        ht.Insert(hash_fn_->GetHash(left_tuple), left_tuple);
    }
    right_->Init();
}

bool isEqual(const Tuple &x, const Tuple &y) {
    return x.id == y.id and x.val1 == y.val1 and x.val2 == y.val2;
}

bool HashJoinExecutor::Next(Tuple *output) {
    Tuple right_tuple;

    while (right_->Next(&right_tuple)) {
        std::vector<Tuple> rows_from_left_with_same_hash;
        ht.GetValue(hash_fn_->GetHash(right_tuple), &rows_from_left_with_same_hash);
        for (auto &candidate_from_left: rows_from_left_with_same_hash) {
            *output = candidate_from_left;
            return true;
        }
    }
    return false;
}
