//
// Created by fugoes on 12/3/16.
//

#ifndef FINAL_FUNCTION_H
#define FINAL_FUNCTION_H

class Function;

#include <list>
#include <string>
#include <map>
#include "Runtime.h"
#include "Atom.h"

/**
 * 用户自定义的函数
 */
class Function {
public:
    /**
     * 默认构造函数
     * @return
     */
    Function();

    /**
     * 析构函数
     */
    ~Function();

    /**
     * 根据传入的语法树构造一个新的函数，并录入FuncEnv属性中
     * @param source
     * 包括构造Function对象所需要的全部信息，比如：
     * (function (test a b)
     *           (assign a (+ a b))
     *           (echo a))
     * 传入参数的内容就是
     *           (test a b)
     *           (assign a (+ a b))
     *           (echo a)
     * 对应的语法树
     */
    static void newFunction(std::list<Atom *> *source);

    /**
     * 根据参数值求函数的返回值
     * @param parasData
     * 参数值
     * @return
     * 指向函数返回的数据的指针
     */
    Data *eval(std::vector<Data *> *parasData);

    /**
     * 调用名称为name的函数，并将相关参数传递过去
     * @param name
     * 被调用函数的名称
     * @param parasData
     * 调用函数时使用的参数
     * @return
     * 指向函数返回的数据的指针
     */
    static Data *call(std::string &name, std::vector<Data *> *parasData);

private:
    /**
     * 用于存储函数的参数名称
     */
    std::list<std::string> paras;
    /**
     * 存储函数体
     */
    std::list<Atom *> body;

    /**
     * 存储函数名及其对应的Function对象
     */
    static std::map<std::string, Function *> FuncEnv;
};

#endif //FINAL_FUNCTION_H
