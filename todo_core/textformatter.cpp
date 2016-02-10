#include "textformatter.h"

namespace todo{

/**
 * @brief Formater::plainText
 * @param data
 * @note Formated as: <message> Tag:<tag> Line:<n>
 * @return
 */
QStringList TextFormatter::plainText(QVector<Task> data){
    QStringList retval;
    QVectorIterator<Task> taskIt(data);
    while(taskIt.hasNext()){
        Task t = taskIt.next();
        QString formated;
        formated.append(t.description);
        formated.append(" Tag:");
        formated.append(t.tag);
        formated.append(" Line:");
        formated.append(t.code_line);
        retval.append(formated);
    }
    return retval;
}

/**
 * @brief Formater::todoText
 * @param data
 * @note Formated as: (A) Line:<n> <message> @<tag>
 * @return
 */
QStringList TextFormatter::todoText(QVector<Task> data){
    QStringList retval;
    QVectorIterator<Task> taskIt(data);
    while(taskIt.hasNext()){
        Task t = taskIt.next();
        QString formated;
        QString priority;
        QString tags = t.tag;

        if(t.description.contains("Auto-generated", Qt::CaseInsensitive)){
            //to clean up code is low priority.
            priority.append("(D) Line:");
            tags.append(" +cleanup");
        }else{
            priority.append("(A) Line:");
        }

        formated.append(priority);
        formated.append(t.code_line);
        formated.append(" ");
        formated.append(t.description);
        formated.append(" @");
        formated.append(tags);

        retval.append(formated);
    }
    return retval;
}

/**
 * @brief Formater::markDown
 * @param data
 * @note Formated as: - [ ] Line:<n> <message> **<tag>**
 * @return
 */
QStringList TextFormatter::markDown(QVector<Task> data){
    QStringList retval;
    QVectorIterator<Task> taskIt(data);

    while(taskIt.hasNext()){
        Task t = taskIt.next();
        QString formated("- [ ] Line:");
        formated.append(t.code_line);
        formated.append(" ");
        formated.append(t.description);
        formated.append(" **");
        formated.append(t.tag);
        formated.append("**");
        retval.append(formated);
    }
    return retval;
}

}//namespace
