//
// Created by fugoes on 12/4/16.
//

#ifndef FINAL_DATANEW_H
#define FINAL_DATANEW_H

class Data;

class Integer;

class Bool;

#include <string>
#include <vector>
#include <iostream>


/**
 * 表示数据的抽象类，数据的类型与值由派生类存储与管理，Data类只负责对数据进行引用计数
 */
class Data {
public:
    /**
     * 默认构造函数，将引用次数设为0
     * @return
     */
    Data();

    /**
     * 用于生成公用的true false数据对象，为了避免这两个对象被析构，在函数体中会将引用次数初始化为1
     * @return
     */
    Data(int);

    /**
     * 虚析构函数
     */
    virtual ~Data() {};

    /**
     * 根据str的内容构造一个数据
     * @param str
     * 作为构造数据时的依据
     * @return
     * str对应的数据，比如str=="123"则返回一个指向值为123的整数类对象的指针
     */
    static Data *newData(const std::string &str);

    /**
     * 检查data对象的引用次数是否为0，如果为0，则析构这个对象
     * @param data
     * 指向被检查的对象的指针
     */
    static void check(Data *data);

    /**
     * 将对象的引用次数减少1
     */
    void uncite();

    /**
     * 将对象的引用次数增加1
     */
    void cite();

    /**
     * 打印对象
     */
    virtual void print() = 0;

    /**
     * 打印对象的详细信息，包括被引用次数等
     */
    virtual void display() = 0;

    /**
     * 任意数量的整数的加法
     * @param dataPara
     * 被加数
     * @return
     * 得到的加法的结果
     */
    static Data *plus(std::vector<Data *> *dataPara);

    /**
     * 两个整数的减法
     * @param dataPara
     * dataPara[0]是被减数，dataPara[1]是减数，更多的参数会被忽略
     * @return
     * 减法的结果
     */
    static Data *minus(std::vector<Data *> *dataPara);

    /**
     * 判断两个数据是否相等
     * @param dataPara
     * 被判断的是dataPara的前两个数据，更多的数据将会被忽略，被比较的数据可以是Bool类的对象，也可以是Integer类的对象
     * @return
     * 一个Bool类型的数据
     */
    static Data *equal(std::vector<Data *> *dataPara);

    /**
     * 任意数量的整数的乘法
     * @param dataPara
     * 被乘数
     * @return
     * 得到的乘法的结果
     */
    static Data *times(std::vector<Data *> *dataPara);

    /**
     * 两个整数的除法
     * @param dataPara
     * dataPara[0]是被除数，dataPara[1]是除数（不能为0），更多的参数会被忽略
     * @return
     * 除法的结果
     */
    static Data *divide(std::vector<Data *> *dataPara);

    /**
     * 比较两个数的大小
     * @param dataPara
     * 被判断的是dataPara的前两个数据，更多的数据将会被忽略，被比较的数据只可以是Integer类
     * @return
     * 一个Bool类型的数据，如果dataPara[0] > dataPara[1]则值为true，否则为false
     */
    static Data *bigger(std::vector<Data *> *dataPara);

    /**
     * 比较两个数的大小
     * @param dataPara
     * 被判断的是dataPara的前两个数据，更多的数据将会被忽略，被比较的数据只可以是Integer类
     * @return
     * 一个Bool类型的数据，如果dataPara[0] < dataPara[1]则值为true，否则为false
     */
    static Data *smaller(std::vector<Data *> *dataPara);

    /**
     * 求两个数的余数
     * @param dataPara
     * dataPara[0]是被除数，dataPara[1]是除数（不能为0），更多的参数会被忽略
     * @return
     * dataPara[0]除以dataPara[1]得到的余数
     */
    static Data *mod(std::vector<Data *> *dataPara);

    /**
     * 逐个打印一组数据
     * @param dataPara
     * 被打印的数据
     * @return
     * 一个值为true的Bool类型数据
     */
    static Data *print(std::vector<Data *> *dataPara);

    /**
     * 逐个打印一组数据的详细信息
     * @param dataPara
     * 被打印的数据
     * @return
     * 一个值为true的Bool类型数据
     */
    static Data *display(std::vector<Data *> *dataPara);

    /**
     * 用于作为全局唯一的值为true的Bool类对象使用
     */
    static Data *trueData;
    /**
     * 用于作为全局唯一的值为false的Bool类对象使用
     */
    static Data *falseData;

private:
    /**
     * 记录当前对象被引用的次数
     */
    unsigned int cited;

    friend class Integer;

    friend class Bool;

    friend class VarEnv;
};

/**
 * 表示一个整数
 */
class Integer : public Data {
public:
    /**
     * 构造函数
     * @return
     */
    Integer();

    /**
     * 将值设置为value
     * @param value
     * 用于初始化value属性的整数
     * @return
     */
    Integer(const long &value);

    /**
     * 析构函数
     */
    virtual ~Integer();

    /**
     * 打印当前对象的值
     */
    virtual void print();

    /**
     * 打印当前对象的详细信息
     */
    virtual void display();

    /**
     * 任意数量的整数的加法
     * @param dataPara
     * 被加数
     * @return
     * 得到的加法的结果
     */
    static Data *plus(std::vector<Data *> *dataPara);

    /**
     * 两个整数的减法
     * @param dataPara
     * dataPara[0]是被减数，dataPara[1]是减数，更多的参数会被忽略
     * @return
     * 减法的结果
     */
    static Data *minus(std::vector<Data *> *dataPara);

    /**
     * 任意数量的整数的乘法
     * @param dataPara
     * 被乘数
     * @return
     * 得到的乘法的结果
     */
    static Data *times(std::vector<Data *> *dataPara);

    /**
     * 两个整数的除法
     * @param dataPara
     * dataPara[0]是被除数，dataPara[1]是除数（不能为0），更多的参数会被忽略
     * @return
     * 除法的结果
     */
    static Data *divide(std::vector<Data *> *dataPara);

private:
    /**
     * 存储对象的数值
     */
    long value;

    friend class Data;

    friend class Runtime;
};

/**
 * 表示一个Bool数据
 */
class Bool : public Data {
public:
    /**
     * 根据value为true或false来初始化
     * @param value
     * 用于初始化value属性
     * @return
     */
    Bool(bool value);

    /**
     * 用于初始化全局使用的true和false
     * @param value
     * @return
     */
    Bool(bool value, int);

    /**
     * 析构函数
     */
    virtual ~Bool();

    /**
     * 打印当前对象的值
     */
    virtual void print();

    /**
     * 打印当前对象的详细信息
     */
    virtual void display();

private:
    /**
     * 存储该对象的值
     */
    bool value;

    friend class Data;

    friend class Bracket;

    friend class Runtime;
};

#endif //FINAL_DATANEW_H
