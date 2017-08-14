//
// Created by ge yao on 2017/8/2.
// 基本二叉树
//

#ifndef TREE_TREE_H
#define TREE_TREE_H
#include <iostream>
#include <queue>
#include <stack>
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

    //遍历的逻辑
    inline void doSomeThing(Node<T>* node){
        if (callBack != nullptr)
            callBack->onShowTime(node->getDataNode());
        if (fCallBack!= nullptr)
            fCallBack(node->getDataNode());
    }
protected:
public:





    //Pre Recursive version
    virtual void preTraversal(Node<T>* node){
        if (node != nullptr){
            doSomeThing(node);
            preTraversal(node->getLeftPoint());
            preTraversal(node->getRightPoint());
        } else{
            return;
        }
    }

    //Mid Recursive version
    virtual void midTraversal(Node<T>* node){
        if (node != nullptr){
            midTraversal(node->getLeftPoint());
            doSomeThing(node);
            midTraversal(node->getRightPoint());
        }
    }

    //Post Recursive version
    virtual void behindTraversal(Node<T>* node){
        if (node != nullptr){
            behindTraversal(node->getLeftPoint());
            behindTraversal(node->getRightPoint());
            doSomeThing(node);
        }
    }

    //Pre Non-Recursive version
    virtual void preTraversal(void){
        //stack of std
        stack<Node<T>* > myStack; // reference cannot be null, use pointer!
        Node<T>* node = getRoot();
        //traversal
        while(node != nullptr || !myStack.empty()){
            //only push left child to prevent dead cycle
            while (node != nullptr){
                doSomeThing(node);
                myStack.push(node);
                node = node->getLeftPoint();
            }
            //get Node and visit
            if (!myStack.empty()){
                node = myStack.top();
                myStack.pop();
                node = node->getRightPoint();
            }
        }
    }


    //Mid Non-Recursive version
    virtual void midTraversal(void){
        //stack of std
        stack<Node<T>* > myStack; // reference cannot be null, use pointer!
        Node<T>* node = getRoot();
        //traversal
        while(node != nullptr || !myStack.empty()){
            //only push left child to prevent dead cycle
            while (node != nullptr){
                myStack.push(node);
                node = node->getLeftPoint();
            }
            //get Node and visit
            if (!myStack.empty()){
                node = myStack.top();
                doSomeThing(node);
                myStack.pop();
                node = node->getRightPoint();
            }
        }
    }

    //Post Non-Recursive version
    virtual void postTraversal(void){
        //stack of std
        stack<Node<T>* > myStack; // reference cannot be null, use pointer!
        Node<T>* node = getRoot();
        //keep the lastVisit node
        Node<T>* lastVisit = getRoot();
        //traversal
        while(node != nullptr || !myStack.empty()){
            //only push left child to prevent dead cycle
            while (node != nullptr){
                myStack.push(node);
                node = node->getLeftPoint();
            }
            //get Node and visit
            if (!myStack.empty()){
                node = myStack.top();
                if (node->getRightPoint() == nullptr || node->getRightPoint() == lastVisit){
                    doSomeThing(node);
                    myStack.pop();
                    lastVisit = node;
                    node = nullptr;
                } else{
                    node = node->getRightPoint();
                }
            }
        }
    }

    //Level easy Non-Recursive version
    virtual void levelEasyTraversal(void){
        //queue of std
        queue< Node<T> >  myQueue;
        if (getRoot() != nullptr){
            myQueue.push(* getRoot()); // this function receive reference var
        }
        while (!myQueue.empty()){
            //get the first node
            Node<T> node = myQueue.front();
            //pop
            myQueue.pop();
            //my business logic, call back
            doSomeThing(&node);
            //deal with children
            if (node.getLeftPoint() != nullptr){
                myQueue.push(* node.getLeftPoint());
            }
            if (node.getRightPoint() != nullptr){
                myQueue.push(* node.getRightPoint());
            }
        }
    }

    //Level Non-Recursive version
    virtual void levelTraversal(void){
        if (getRoot() == nullptr){
            return;
        }
        queue<Node<T>*> myQueue;
        myQueue.push(getRoot());
        myQueue.push(0); // nullptr

        do{
            Node<T>* node = myQueue.front();
            myQueue.pop();
            if (node){ // node != nullptr
                doSomeThing(node);
                if (node->getLeftPoint() != nullptr){
                    myQueue.push( node->getLeftPoint());
                }
                if (node->getRightPoint() != nullptr){
                    myQueue.push(node->getRightPoint());
                }
            } else{
                if (!myQueue.empty()){
                    //end the the level
                    myQueue.push(0);
                    cout << endl;
                }
            }
        }while (!myQueue.empty());
    }

    //设置面向对象的回调成员变量
    void setCallBack(TCallBack<T> *callBack) {
        this -> callBack = callBack;
    }
    //设置面向过程的回调函数
    void setFCallBack( T &(*back)(T &) ) {
        Tree::fCallBack = back;
    }

    virtual Node<T> *getRoot() const {
        return root;
    }

    virtual void setRoot(Node<T> *root) {
        this -> root = root;
    }

};




#endif //TREE_TREE_H
