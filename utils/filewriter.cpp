#include "filewriter.h"

/**
 * @brief utils::FileWriter::writeFile
 * @param filename
 * @param value
 * @param append
 */
void utils::FileWriter::writeFile(QString filename, QString value, bool append){
    if(filename != ""){
        QString nativePath = QDir::toNativeSeparators(filename);
        QFile file(nativePath);
        if( (!file.exists()) || (file.exists() && append) ){
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream out(&file);
            out << value;
            file.close();
        } else {
            qDebug() << "Could not open " << filename;
        }
    }
}

/**
 * @brief utils::FileWriter::writeFile
 * @param filename
 * @param stringList
 * @param append
 */
void utils::FileWriter::writeFile(QString filename, QStringList stringList, bool append){
    qDebug() << "stringList.size: " << stringList.size();
    if(filename != ""){
        QString nativePath = QDir::toNativeSeparators(filename);
        QFile file(nativePath);
        if( (!file.exists()) || (file.exists() && append) ){
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            for(int i=0; i < stringList.size(); i++ ){
                QTextStream out(&file);
                out << stringList.at(i) << '\n';
            }
            file.close();
        } else {
            qDebug() << "Could not open " << filename;
        }
    }
}
