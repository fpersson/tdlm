#include "filelister.h"

namespace utils{

FileLister::FileLister(){
}

QStringList FileLister::listFiles(QString dir, QStringList filter){
    QStringList retlist;
    QDir::toNativeSeparators(dir);
    QDir workingdir(dir);

    if( workingdir.exists() && workingdir.isReadable() ){
        workingdir.setFilter(QDir::Files | QDir::Dirs | QDir::NoSymLinks);
        QFileInfoList list = workingdir.entryInfoList();
        for(int i = 2; i < list.size(); i++){
            QFileInfo info = list.at(i);
            if(info.isDir()){
                retlist.append(listFiles(info.absoluteFilePath(), filter));
            }else{
                for(int j=0; j<filter.size(); j++){
                    if(info.fileName().endsWith(filter.at(j))){
                        retlist.append(info.absoluteFilePath());
                    }
                }
            }
        }
    }
    return retlist;
}

}//namespace

