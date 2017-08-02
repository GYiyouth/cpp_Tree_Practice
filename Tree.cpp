//
// Created by ge yao on 2017/8/2.
//
#include <iostream>
#include "Tree.h"
using namespace std;

template <class T>
class CallBackEntity: public TCallBack<T>{
public:
    void onShowTime(T &data) const override {
        cout << data << endl;
    }
};

void treeTest(){
    int a = 1;
    auto root = new Node<int>(a);


    Tree<int>* tree = new Tree<int>();
    tree->setRoot(root);

    CallBackEntity<int>* callBackEntity = new CallBackEntity<int>();

    tree->setCallBack(callBackEntity);

    tree->preTraversal(tree->getRoot());
}

