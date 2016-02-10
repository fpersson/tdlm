#ifndef TODOPARSER_H
#define TODOPARSER_H

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

#include <QVector>
#include <QStringList>
#include <QDebug>

#include "task.h"

namespace todo{
    class TodoParser{
    public:
        TodoParser();
        QStringList getTodos(QStringList data);
        QVector<Task> getTask(QStringList data);
        void setTag(QString tag);
    private:
        QString cleanUp(QString str);
        QString m_tag;
    };
}

#endif // TODOPARSER_H
