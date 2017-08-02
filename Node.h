//
// Created by ge yao on 2017/8/2.
// 二叉树的节点，包含，左指针，左权值，数据节点，右权值，右指针
//

#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <iostream>
using namespace std;
template <class T>
class Node {
private:
    Node<T>* leftPoint = nullptr;
    int leftValue = 0;
    T& dataNode = (T) NULL;
    int rightValue = 0;
    Node<T>* rightPoint = nullptr;
protected:
public:
    Node() {
    }
    //在一开始一定要对引用变量赋一个合法的初值
    Node(T &dataNode) : dataNode(dataNode) {

    }

    virtual Node<T> *getLeftPoint() const {
        return leftPoint;
    }

    virtual void setLeftPoint(Node<T> *leftPoint) {
        Node::leftPoint = leftPoint;
    }

    virtual int getLeftValue() const {
        return leftValue;
    }

    virtual void setLeftValue(int leftValue) {
        Node::leftValue = leftValue;
    }

    virtual T &getDataNode() const {
        return dataNode;
    }

    virtual void setDataNode(T &dataNode) {
        Node::dataNode = dataNode;
    }

    virtual int getRightValue() const {
        return rightValue;
    }

    virtual void setRightValue(int rightValue) {
        Node::rightValue = rightValue;
    }

    virtual Node<T> *getRightPoint() const {
        return rightPoint;
    }

    virtual void setRightPoint(Node<T> *rightPoint) {
        Node::rightPoint = rightPoint;
    }
};


#endif //TREE_NODE_H
