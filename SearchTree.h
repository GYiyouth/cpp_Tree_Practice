//
// Created by ge yao on 2017/8/15.
// 二叉查找树
//

#ifndef TREE_SEARCHTREE_H
#define TREE_SEARCHTREE_H

#include "Tree.h"

class SearchTree: public Tree<int> {
public:

    SearchTree() = default;


    /**
     * 变为二叉查找树
     *
     * 构造函数不能用virtual修饰
     * @param array
     * @param length
     * @param tree
     */
    SearchTree(int *array, int length){
        if (length <= 0){
            this->setRoot(nullptr);
            return;
        }
        Node<int>* node = new Node<int>(array[0]);
        this->setRoot(node);
        for (int i = 1; i < length; ++i) {
            insertValue(array[i]);
        }
    }

    /**
     * 插入一个新的数字
     * @param newValue
     * @return
     */
    virtual bool insertValue(int & newValue){
        Node<int>* node = getRoot();
        Node<int>* parent;
        bool leftFlag = true;
        if (node == nullptr){
            node = new Node<int>(newValue);
            setRoot(node);
            return true;
        }
        //找寻可插入的节点
        parent = getParent(newValue, leftFlag);
        node = new Node<int>(newValue);
        //在父节点下插入
        insertNode(parent, node);
    }

    /**
     * 找寻目标大小的节点的父节点
     * 如果不存在，返回刚好可以插入的节点，该节点必然可以在左或者右边插入该value
     * 如果是根节点，或者树为空，返回nullptr
     *
     * @param targetValue 要寻找的值
     * @param leftFlag true，则往左边插入，false，往右边插入
     * @return
     */
    virtual Node<int>* getParent(int & targetValue, bool & leftFlag){
        Node<int>* parent = getRoot();
        if (parent == nullptr || parent->getDataNode() == targetValue){
            return nullptr;
        }
        while (parent){
            if (targetValue <= parent->getDataNode()){
                //如果左节点为空，或者左节点就是该值
                if (parent->getLeftPoint() == nullptr
                    || parent->getLeftPoint()->getDataNode() == targetValue){
                    leftFlag = true;
                    return parent;
                }
                parent = parent->getLeftPoint();
            } else {
                if (parent->getRightPoint() == nullptr
                    || parent->getRightPoint()->getDataNode() == targetValue){
                    leftFlag = false;
                    return parent;
                }
                parent = parent->getRightPoint();
            }
        }
    }

    /**
     * 只适用于2个节点的子孙节点没有重合
     *
     * 在二叉树上插入一个节点，如果有节点为空，或者2个节点是同一个，失败
     * 如果有data相等的节点，插入到做孩子中。
     * @param targetNode 插入在这个节点下方
     * @param newNode 要插入的节点，完成后肯定是叶子节点
     */
    virtual bool insertNode(Node<int>* targetNode, Node<int>* newNode){
        if (targetNode == nullptr || newNode == nullptr || targetNode == newNode){
            return false;
        }
        if (getRoot() == nullptr){
            setRoot(newNode);
            return true;
        }
        const int value = newNode->getDataNode();
        while(targetNode != nullptr){
            if (value <= targetNode->getDataNode()){
                //插入在左边
                if (targetNode->getLeftPoint() == nullptr){
                    targetNode->setLeftPoint(newNode);
                    return true;
                }
                targetNode = targetNode->getLeftPoint();
            } else{
                //插入在右边
                if (targetNode->getRightPoint() == nullptr){
                    targetNode->setRightPoint(newNode);
                    return true;
                }
                targetNode = targetNode->getRightPoint();
            }
        }
    }

    /**
     * 查找第一个与目标值相等的节点
     * 如果不存在，则返回nullptr
     * @param target 目标值
     * @return
     */
    virtual Node<int>* find(int& target){
        if (getRoot() == nullptr){
            return nullptr;
        }
        bool leftFlag;
        //找寻父节点
        Node<int>* node = getParent(target, leftFlag);
        //如果是根节点
        if (node == nullptr){
            if (getRoot()->getDataNode() == target){
                return getRoot();
            }
            return nullptr;
        }
        if (leftFlag){
            node = node->getLeftPoint();
        } else{
            node = node->getRightPoint();
        }
        return node;
    }

    /**
     * 删除
     * 讨论一下情况：
     * 空树，或者节点不存在，返回nullptr
     * 节点存在，是根节点
     * 节点不存在，不是根节点，
     * @param targetValue
     * @return
     */
    virtual Node<int>* deleteValue(int& targetValue){
        Node<int>* targetNode = find(targetValue);
        if (targetNode == nullptr){
            //节点不存在，或者树为空
            return nullptr;
        }
        //节点存在，树不为空
        bool leftFlag = true;
        //找到父节点，如果目标节点是根节点，则返回nullptr
        Node<int>* parent = getParent(targetValue, leftFlag);
        //如果目标节点有左孩子，根设置为左孩子，没有的话，设置为右孩子
        Node<int>* root = targetNode->getLeftPoint() != nullptr
                          ? targetNode->getLeftPoint()
                          : targetNode->getRightPoint();
        if (parent == nullptr){
            //要删除的是根节点，不用考虑父节点的情况
            //如果没有孩子节点
            if (targetNode->getLeftPoint() == nullptr
                && targetNode->getRightPoint() == nullptr){
                setRoot(nullptr);
                return targetNode;
            }
            //设置根节点
            setRoot(root);
            //把右节点插入到根节点下，插入函数考虑了nullptr以及相同的情况。
            insertNode(root, targetNode->getRightPoint());
            return targetNode;
        }
        //删除的节点不是根节点
        if (leftFlag){
            //目标节点在左边
            parent->setLeftPoint(root);
        } else {
            //目标节点在右边
            parent->setRightPoint(root);
        }
        insertNode(root, targetNode->getRightPoint());
        return targetNode;
    }
};

#endif //TREE_SEARCHTREE_H
