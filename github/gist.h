#ifndef GIST_H
#define GIST_H
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

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

namespace Github{
    class Gist{
    public:
        Gist();

        void setDesription(QString description);
        void setIsPublic(bool isPublic);
        void setFilename(QString filename);
        void setContent(QString content);

        QJsonObject getGistObject();
    private:
        QString m_description;
        QString m_filename;
        QString m_content;
        bool m_isPublic;
    };
} //namespace

#endif // GIST_H
