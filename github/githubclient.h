#ifndef GITHUBCLIENT_H
#define GITHUBCLIENT_H
/*
    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA  02110-1301, USA.

    ---
    Copyright (C) 2015, Fredrik Persson <fpersson.se@gmail.com>
 */

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDir>
#include <QDebug>

#include <QJsonObject>
#include <QJsonDocument>

namespace Github {
    class GithubClient : public QObject
    {
    Q_OBJECT
    public:
        explicit GithubClient(QString oauth, QString username, QObject *parent = 0);
        void setOauth(QString oauth){ m_oauth = oauth;}
        void setUnserName(QString name){ m_username = name;}
        void post(QJsonObject obj);
    signals:

    public slots:
        void readData(QNetworkReply *data);

    private:
        QNetworkAccessManager m_networkManager;
        QString m_username;
        QString m_oauth;
    };
}//namespace

#endif // GITHUBCLIENT_H
