//
// Created by fugoes on 12/2/16.
//

#ifndef FINAL_ATOM_H
#define FINAL_ATOM_H

class Atom;

class Bracket;

class Symbol;

#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <cassert>

#include "Data.h"
#include "Runtime.h"
#include "Function.h"
#include "VarEnv.h"

/**
 * 用于存储语法结构的抽象类
 */
class Atom {
public:
    /**
     * 空构造函数
     * @return
     */
    Atom() {};

    /**
     * 虚析构函数
     */
    virtual ~Atom() {};

    /**
     * 显示语法树，并且使用indent级的缩进
     * @param indent
     */
    virtual void display(int indent) = 0;

    /**
     * 根据runtime来求Atom对应的值
     * @param runtime
     * 用于获取变量对应的数据、进行赋值运算等
     * @return
     * 当前Atom的值，比如如果当前Atom是(add 1 2)则返回一个值为3的数据
     */
    virtual Data *eval(Runtime *runtime) = 0;

    /**
     * 复制一个Atom并返回
     * @return
     */
    virtual Atom *copy() = 0;
};

/**
 * 用于存储一个括号的语法结构的类
 */
class Bracket : public Atom {
public:
    /**
     * 从pos位置开始，从str字符串中取出一个完整的括号表达式，并生成该表达式对应的语法树存储在新建的Bracket对象里
     * @param str
     * 源代码
     * @param pos
     * 用于作为“光标”所在位置，函数会修改pos到获取的完整的括号表达式最后一个字符的位置加一
     * @return
     */
    Bracket(const std::string &str, unsigned long &pos);

    /**
     * 默认的空构造函数
     * @return
     */
    Bracket();

    /**
     * 析构函数
     */
    virtual ~Bracket();

    /**
     * 打印Bracket对象对应的语句，并使用indent级的缩进
     * @param indent
     * 打印时使用的缩进深度
     */
    virtual void display(int indent);

    /**
     * 根据runtime来求本对象对应的表达式的值
     * @param runtime
     * 用于获取求值时需要的变量的值以及进行赋值操作等
     * @return
     * 本对象对应表达式的值
     */
    virtual Data *eval(Runtime *runtime);

    /**
     * 复制一份当前对象并返回
     * @return
     * 复制得到的对象
     */
    virtual Atom *copy();

private:
    /**
     * 用于存储该表达式对应的函数名称，比如(test 1 2)对应的表达式的函数名称就是test
     */
    std::string func;
    /**
     * 用于存储参数对应的语法结构
     */
    std::list<Atom *> para;

    /**
     * 根据para属性生成参数的具体数据
     * @param runtime
     * 求参数的数据时，从runtime中获取变量名对应的数据以及进行赋值操作等
     * @return
     * 返回一个根据参数生成的数据的vector
     */
    std::vector<Data *> *genParaData(Runtime *runtime);

    friend class Runtime;

    friend class Function;
};

/**
 * 用于存储一个符号对应的语法结构，这个符号可以是一个常量，也可以是一个变量名，比如(test 1 2 a)中的1、2、a都是一个符号
 */
class Symbol : public Atom {
public:
    /**
     * 根据str来构造
     * @param str
     * 比如为"true" "false" "123" "a"等
     * @return
     */
    Symbol(const std::string &str);

    /**
     * 析构函数
     */
    virtual ~Symbol();

    /**
     * 打印本对象对应的符号，并使用indent级的缩进
     * @param indent
     * 打印时使用的缩进级数
     */
    virtual void display(int indent);

    /**
     * 获取当前对象的值，比如如果name属性是一个常量，比如"123"，就返回一个值为123的整数数据，如果是变量名就在runtime中查询该变量名对应的数据并且返回
     * @param runtime
     * 用于获取变量对应的数据
     * @return
     * 如果name属性是一个常量，比如"123"，就返回一个值为123的整数数据，如果是变量名就在runtime中查询该变量名对应的数据并且返回
     */
    virtual Data *eval(Runtime *runtime);

    /**
     * 复制当前对象并返回
     * @return
     * 返回复制得到的对象
     */
    virtual Atom *copy();

private:
    /**
     * 用于存储符号对应的字符串，比如"a" "123" "true" "false"等
     */
    std::string name;

    friend class Runtime;

    friend class Bracket;

    friend class Function;
};

#endif //FINAL_ATOM_H
