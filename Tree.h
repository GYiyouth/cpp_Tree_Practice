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
    //回调函数
    T& (* fCallBack)(T& data);
protected:
public:

    //前序遍历,递归版本
    virtual void preTraversal(Node<T>* node){
        if (node != nullptr){
            if (callBack != nullptr)
                callBack->onShowTime(node->getDataNode());
            if (fCallBack!= nullptr)
                fCallBack(node->getDataNode());
            preTraversal(node->getLeftPoint());
            preTraversal(node->getRightPoint());
        } else{
            return;
        }
    }
    //设置面向对象的回调成员变量
    void setCallBack(TCallBack<T> *callBack) {
        this -> callBack = callBack;
    }
    //设置面向过程的回调函数
    void setFCallBack(T &(*fCallBack)(T &)) {
        Tree::fCallBack = fCallBack;
    }

    virtual Node<T> *getRoot() const {
        return root;
    }

    virtual void setRoot(Node<T> *root) {
        this -> root = root;
    }

};




#endif //TREE_TREE_H
