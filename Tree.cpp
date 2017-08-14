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
    cout << "function pointer : " << data << endl;
}
//使用实例
void treeTest(){
    int a = 1;
    //树
    auto tree = new Tree<int>();
    //根节点
    auto root = new Node<int>(a);
    //做2个孩子
    auto b = a + 1 ;
    auto left = new Node<int>(b);
    auto c = b + 1 ;
    auto right = new Node<int>(c);
    root->setLeftPoint(left);
    root->setRightPoint(right);
    auto ll = 4;
    auto lr = 5;
    auto rl = 6;
    auto rr = 7;
    auto l1 = new Node<int>(ll);
    auto l2 = new Node<int>(lr);
    auto r1 = new Node<int>(rl);
    auto r2 = new Node<int>(rr);
    left->setLeftPoint(l1);
    left->setRightPoint(l2);
    right->setLeftPoint(r1);
    right->setRightPoint(r2);


    //继承了回调接口的类
    auto callBackEntity = new CallBackEntity<int>();
    tree->setRoot(root);
    //设置面向对象的回调
    tree->setCallBack(callBackEntity);
    //设置函数指针
    tree->setFCallBack(onPointShow);
    cout << "Pre Recursive function" << endl;
    //递归前序遍历测试
    tree->preTraversal(tree->getRoot());

    cout << endl;

    cout << "Pre Non-Recursive function" << endl;
    tree->preTraversal();

    cout << endl;

    cout << "Mid Non-Recursive function" << endl;
    tree->midTraversal();

    cout << endl;

    cout << "Post Non-Recursive function" << endl;
    tree->postTraversal();

    cout << endl;

    cout << "Level easy Non-Recursive function" <<endl;
    tree->levelEasyTraversal();

    cout << endl;

    cout << "Level Non-Recursive function" <<endl;
    tree->levelTraversal();
}

