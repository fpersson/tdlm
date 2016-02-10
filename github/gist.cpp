#include "gist.h"
namespace Github{

Gist::Gist(){
    m_description = "Gist Description";
    m_filename = "todo.md";
    m_isPublic = false;
    m_content = " - [ ] something todo. ";
    m_content.append('\n');
    m_content.append(" - [ ] something more todo. ");
}

void Gist::setDesription(QString description){
    m_description = description;
}

void Gist::setFilename(QString filename){
    m_filename = filename;
}

void Gist::setContent(QString content){
    m_content = content;
}

void Gist::setIsPublic(bool isPublic){
    m_isPublic = isPublic;
}

QJsonObject Gist::getGistObject(){
    QJsonObject json;
    QJsonObject file;
    QJsonObject content;

    json["description"] = m_description;
    json["public"] = m_isPublic;

    content["content"] = m_content;
    file[m_filename] = content;

    json["files"] = file;

    return json;
}

} //namespace

