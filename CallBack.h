//
// Created by ge yao on 2017/8/2.
// 用来做回调的接口
//

#ifndef TREE_CALLBACK_H
#define TREE_CALLBACK_H


class CallBack {
public:
    virtual void onShowTime() const = 0;
};

/**
 * 树专用的回调指针
 * @tparam T
 */
template <class T>
class TCallBack{
public:
    virtual T& onShowTime(T& data) const = 0;
};

#endif //TREE_CALLBACK_H
