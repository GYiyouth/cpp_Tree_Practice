//
// Created by ge yao on 2017/8/2.
//
#include <iostream>
#include "Tree.h"
#include "SearchTree.h"
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

//把一个数组变成二叉查找树
void initSearchTree(int* array, int length, Tree<int>& tree){
    if (length == 0){
        tree.setRoot(nullptr);
        return;
    }
    Node<int>* node = new Node<int>(array[0]);
    Node<int>* parent = nullptr;
    bool isLeft = true;
    tree.setRoot(node);
    for (int i = 1; i < length; ++i) {
        node = tree.getRoot();
        while (node){
            parent = node;
            if (array[i] <= node->getDataNode()){
                node = node->getLeftPoint();
                isLeft = true;
            } else if (array[i] > node->getDataNode()){
                    node = node->getRightPoint();
                    isLeft = false;
            }
        }
        node = new Node<int>(array[i]);
        if (isLeft){
            parent->setLeftPoint(node);
        } else {
            parent->setRightPoint(node);
        }
    }
}


//使用实例
void treeTest(){
    int a = 1;
    //树
    int array[9]= {5,9,2,8,4,7,1,3,6};
    auto tree = new SearchTree(array, sizeof(array)/ sizeof(array[0]));
    //设置函数指针
    tree->setFCallBack(onPointShow);
    tree->midTraversal();
    int temp = 9;
    Node<int>* node = tree->find(temp);
    cout << (tree->deleteValue(temp) == node) << endl;
    tree->midTraversal();
    return;

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

