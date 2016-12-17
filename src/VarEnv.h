//
// Created by fugoes on 12/2/16.
//

#ifndef FINAL_VARENV_H
#define FINAL_VARENV_H

class VarEnv;

#include <map>
#include <string>
#include <list>
#include "Data.h"


/**
 * 变量环境
 */
class VarEnv {
public:
    /**
     * 构造函数
     * @return
     */
    VarEnv();

    /**
     * 析构函数
     */
    ~VarEnv();

    /**
     * 获取name变量名对应的数据
     * @param name
     * 待获取的变量的名称
     * @return
     * name对应的数据，如果未找到，返回的是NULL
     */
    Data *getVar(const std::string &name);

    /**
     * 将变量名name指向data数据，如果没有在Runtime中找到name变量，就会新建一个名称为name的变量，并指向data，如果找到了，则将name原来指向的数据的被引用次数减少一，在将name指向data
     * @param name
     * 被赋值的变量名称
     * @param data
     * 待赋值的数据
     */
    void assignVar(const std::string &name, Data *data);

    /**
     * 打印该对象中所有的变量的详细信息
     */
    void display();

private:
    /**
     * 用于存储变量名及其对应的数据
     */
    std::map<std::string, Data *> vars;
};

#endif //FINAL_VARENV_H
