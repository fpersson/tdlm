#include "outputmanager.h"

/**
 * @brief todo::OutputManager::stdout as the name say....
 * @param stringList
 */
void todo::OutputManager::stdout(QStringList stringList){
    for(int j=0; j<stringList.size();j++){
        std::cout << QString(stringList.at(j)).toStdString() << std::endl;
    }
}

/**
 * @brief todo::OutputManager::tofile
 * @param stringList
 * @param filename
 */
void todo::OutputManager::tofile(QStringList stringList, QString filename){
    utils::FileWriter fw;
    fw.writeFile(filename, stringList, false);
}

