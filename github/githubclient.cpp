#include "githubclient.h"

namespace Github {

/**
 * @brief GithubClient::GithubClient
 * @param oauth
 * @param username
 * @param parent
 */
GithubClient::GithubClient(QString oauth, QString username, QObject *parent) : QObject(parent) {
    m_oauth = oauth;
    m_username = username;
    connect(&m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readData(QNetworkReply*)));
}

/**
 * @brief GithubClient::post post a json formated gist to github
 * @param obj
 */
void GithubClient::post(QJsonObject obj){
    QNetworkRequest request(QUrl(QString("https://api.github.com/gists?access_token="+m_oauth)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray postData;
    QJsonDocument doc(obj);
    postData.append(doc.toJson());
    m_networkManager.post(request, postData);
}

/**
 * @brief GithubClient::readData
 * @param data
 * @todo implement in the future.
 */
void GithubClient::readData(QNetworkReply *data){
   qDebug() << "Data: " << data->readAll();
}

} //namespace

