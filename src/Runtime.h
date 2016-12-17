//
// Created by fugoes on 12/2/16.
//

#ifndef FINAL_RUNTIME_H
#define FINAL_RUNTIME_H

class Runtime;

#include <list>
#include <forward_list>
#include "VarEnv.h"
#include "Atom.h"

/**
 * 运行时，运行一段代码时，会从Runtime对象中获得变量名对应的数据，以及进行赋值操作等
 */
class Runtime {
public:
    /**
     * 构造函数
     * @return
     */
    Runtime();

    /**
     * 析构函数
     */
    ~Runtime();

    /**
     * 将变量名name指向data数据，如果没有在Runtime中找到name变量，就会新建一个名称为name的变量，并指向data，如果找到了，则将name原来指向的数据的被引用次数减少一，在将name指向data
     * @param name
     * 被赋值的变量名称
     * @param data
     * 待赋值的数据
     */
    void assignVar(std::string &name, Data *data);

    /**
     * 在最顶层的VarEnv中新建变量并赋值，用于实现函数调用时传递参数
     * @param name
     * 被赋值的变量名称
     * @param data
     * 待赋值的数据
     */
    void assignVarToTop(std::string &name, Data *data);

    /**
     * 将name对应的整数重新设置为data的值，和assign的区别在于，set会改变name指向的数据的值
     * @param name
     * 被赋值的变量名称
     * @param data
     * 待赋值的数据
     */
    void setVar(std::string &name, Data *data);

    /**
     * 获取name变量名对应的数据
     * @param name
     * 待获取的变量的名称
     * @return
     * name对应的数据
     */
    Data *getVar(std::string &name);

    /**
     * 构造一个VarEnv并入栈
     */
    void pushVarEnv();

    /**
     * 出栈一个VarEnv并析构它
     */
    void popVarEnv();

    /**
     * 打印该对象中所有的变量的详细信息
     */
    void display();

private:
    /**
     * 作为一个存储变量的栈使用
     */
    std::forward_list<VarEnv *> varEnvs;
};

#endif //FINAL_RUNTIME_H
