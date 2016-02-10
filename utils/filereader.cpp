#include "filereader.h"

utils::FileReader::FileReader(){}

/**
 * @brief utils::FileReader::getLines
 * @param filpath
 * @return
 */
QStringList utils::FileReader::getLines(QString filepath){
    QStringList retval;
    if(filepath != ""){
        QString nativePath = QDir::toNativeSeparators(filepath);
        QFile file(nativePath);
        if(file.exists()){
            if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
                QTextStream in(&file);
                while(!in.atEnd()){
                    QString line = in.readLine();
                    retval.append(line);
                }
            }
        }
    }
    return retval;
}

/**
 * @brief utils::FileReader::getString
 * @param filepath
 * @return
 */
QString utils::FileReader::getString(QString filepath){
    QString retval;
    if(filepath != ""){
        QString nativePath = QDir::toNativeSeparators(filepath);
        QFile file(nativePath);
        if(file.exists()){
            if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
                QTextStream in(&file);
                while(!in.atEnd()){
                    QString line = in.readLine();
                    retval.append(line);
                }
            }
        }
    }
    return retval;
}

