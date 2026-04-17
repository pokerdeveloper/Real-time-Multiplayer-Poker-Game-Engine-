#ifndef _DBOPERATOR_H_
#define _DBOPERATOR_H_

#include <string>
#include <map>

//
#include <util/tc_config.h>
#include <util/tc_mysql.h>
#include <util/tc_singleton.h>
#include <wbl/pthread_util.h>

//
#include "OuterFactoryImp.h"

//
using namespace std;
using namespace tars;

/**
 *
*/
class CDBOperator
{
public:
    /**
     *
    */
    CDBOperator();

    /**
     *
    */
    ~CDBOperator();

public:
    //初始化
    int init(const TLogConfig &tLogConfig);

public:
    //日志入库
    int log(int id, const std::string &buffer);
    //日志入库
    int log(const vector<string> &vecItem);
    //日志入库
    int log(const vector<vector<string> > &vecItem);
    //日志查询
    int queryDB(const string &szCondition, vector<vector<string> > &vecItem);

private:
    TC_Mysql m_mysqlObj;

private:
    //wbl::ReadWriteLocker m_rwlock;

private:
    TLogConfig m_tLogConfig;  //日志配置
};

//typedef TC_Singleton<CDBOperator, CreateStatic, DefaultLifetime> DBOperatorSingleton;

#endif


