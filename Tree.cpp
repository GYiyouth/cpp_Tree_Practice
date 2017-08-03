//
// Created by ge yao on 2017/8/2.
//
#include <iostream>
#include "Tree.h"
using namespace std;

//callback in oop
template <class T>
class CallBackEntity: public TCallBack<T>{
public:
    T& onShowTime(T &data) const override {
        cout << "Object call back : " << data << endl;
    }
};

//call back in Procedural programming
//templates can't be virtual
template <class T>
T& onPointShow(T& data){
    cout << "function pointer :" << data << endl;
}
//使用实例
void treeTest(){
    int a = 1;
    //树
    auto tree = new Tree<int>();
    //根节点
    auto root = new Node<int>(a);
    //继承了回调接口的类
    auto callBackEntity = new CallBackEntity<int>();
    tree->setRoot(root);
    //设置
    tree->setCallBack(callBackEntity);
    //遍历测试
    tree->preTraversal(tree->getRoot()); //Object call back : 1
    //设置函数指针
    tree->setFCallBack(onPointShow);
    //再次遍历测试
    tree->preTraversal(tree->getRoot());
}

