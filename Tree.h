//
// Created by ge yao on 2017/8/2.
// 基本二叉树
//

#ifndef TREE_TREE_H
#define TREE_TREE_H
#include <iostream>
#include "Node.h"
#include "CallBack.h"



template <class T>
class Tree {
private:
    //根节点
    Node<T>* root = nullptr;
    //回调函数，在遍历时可以做一些事情
    TCallBack<T>* callBack = nullptr;
protected:
public:



    virtual Node<T> *getRoot() const {
        return root;
    }

    virtual void setRoot(Node<T> *root) {
        this -> root = root;
    }

    //前序遍历
    virtual void preTraversal(Node<T>* node){
        if (node != nullptr){
            callBack->onShowTime(node->getDataNode());
            preTraversal(node->getLeftPoint());
            preTraversal(node->getRightPoint());
        } else{
            return;
        }
    }

    //设置回调成员变量
    void setCallBack(TCallBack<T> *callBack) {
        this -> callBack = callBack;
    }
};




#endif //TREE_TREE_H
