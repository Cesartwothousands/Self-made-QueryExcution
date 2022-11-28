#include "../include/nested_loop_join_executor.h"

NestedLoopJoinExecutor::NestedLoopJoinExecutor (AbstractExecutor *left_child_executor, AbstractExecutor *right_child_executor, const std::string join_key)
    : left_(left_child_executor), right_(right_child_executor), join_key_(join_key){};

void NestedLoopJoinExecutor::Init() { left_->Init(); }

std::string join_key_value (Tuple tuple, std::string join_key) {
    if (join_key == "id")        return std::to_string(tuple.id);
    else if (join_key == "val1") return std::to_string(tuple.val1);
    else if (join_key == "val2") return tuple.val2;
    return NULL;
}


bool isEqual(const Tuple &left_tuple, const Tuple &right_tuple, std::string join_key_) {
    return join_key_value(left_tuple, join_key_) == join_key_value(right_tuple, join_key_);
}

bool NestedLoopJoinExecutor::Next(Tuple *tuple) {
    Tuple left_tuple, right_tuple;

    while (left_->Next(&left_tuple)) {
        right_->Init();
        while (right_->Next(&right_tuple)) {
            if (isEqual (right_tuple, left_tuple, join_key_)) {
                *tuple = right_tuple;
                return true;
            }
        }
    }
    return false;
}
