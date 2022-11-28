#include "../include/nested_loop_join_executor.h"

NestedLoopJoinExecutor::NestedLoopJoinExecutor(
    AbstractExecutor *left_child_executor,
    AbstractExecutor *right_child_executor, const std::string join_key)
    : left_(left_child_executor),
      right_(right_child_executor),
      join_key_(join_key){};

void NestedLoopJoinExecutor::Init() {
    left_->Init();
}

bool NestedLoopJoinExecutor::join_helper(const Tuple &left, const Tuple &right) {
    if (join_key_ == "val1"){
        return left.val1 == right.val1;
    } else if (join_key_ == "val2"){
        return left.val2 == right.val2;
    }
    return left.id == right.id;
}

bool NestedLoopJoinExecutor::Next(Tuple *tuple) {
    while (left_->Next(tuple)){
        Tuple left_tuple = *tuple;
        right_->Init();
        while(right_->Next(tuple)){
            Tuple right_tuple = *tuple;
            if (join_helper(left_tuple, right_tuple)){
                return true;
            }
        }
    }
    return false;
}

