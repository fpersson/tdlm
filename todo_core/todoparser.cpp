#include "todoparser.h"

namespace todo {

TodoParser::TodoParser(){
    m_tag="";
}

/**
 * @brief TodoParser::getTodos less advanced form.
 * @param data
 * @return
 */
QStringList TodoParser::getTodos(QStringList data){
    QStringList retval;
    if(!data.empty()){
        for(int i = 0; i < data.size(); i++){
            if(data.at(i).contains("todo", Qt::CaseInsensitive) ){
                QString result = cleanUp(data.at(i));
                retval.append(result);
            }
        }
    }
    return retval;
}

void TodoParser::setTag(QString tag){
    m_tag = tag;
}

/**
 * @brief TodoParser::getTask
 * @param data
 * @return
 */
QVector<Task> TodoParser::getTask(QStringList data){
    QVector<Task> retval;
    if(!data.empty()){
        for(int i = 0; i < data.size(); i++){
            if(data.at(i).contains("todo", Qt::CaseInsensitive) ){
                Task tmpTask;
                tmpTask.code_line = QString::number(i+1); //files start at line 1
                tmpTask.description = cleanUp(data.at(i));
                tmpTask.tag = m_tag;
                retval.append(tmpTask);
            }
        }
    }
    return retval;
}

/**
 * @brief TodoParser::cleanUp
 * @param str
 * @return
 */
QString TodoParser::cleanUp(QString str){
    QString retval;
    retval = str.trimmed();

    //@todo remove hardcoded patterns and replace it with a user configuration, json?
    retval.replace(QString("/**"), QString(""));
    retval.replace(QString("///"), QString(""));
    retval.replace(QString("//"), QString(""));
    retval.replace(QString("/*"), QString(""));
    retval.replace(QString("* "), QString(""));
    retval.replace(QString("*/"), QString(""));
    retval.replace(QString("@"), QString(""));
    retval.replace(QString("todo"), QString(""), Qt::CaseInsensitive);

    return retval.trimmed();
}

}//namespace

