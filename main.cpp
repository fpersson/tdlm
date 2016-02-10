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

#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QCommandLineParser>
#include <QJsonObject>


#include "todo_core/todoparser.h"
#include "todo_core/textformatter.h"
#include "todo_core/task.h"
#include "todo_core/outputmanager.h"
#include "github/githubclient.h"
#include "github/gist.h"
#include "utils/filelister.h"
#include "utils/filereader.h"

int main(int argc, char *argv[]){
    qputenv("QT_LOGGING_RULES", "qt.network.ssl.warning=false");
    QCoreApplication a(argc, argv);
    QCommandLineParser cmd;
    Github::GithubClient client("", "");
    utils::FileLister fileLister;
    utils::FileReader fileReader;
    todo::TodoParser parser;
    todo::TextFormatter formatter;

    a.setApplicationName("tdlm");
    a.setApplicationVersion("0.0.2");

    cmd.setApplicationDescription("tdlm, ToDo List Maker.");
    cmd.addVersionOption();
    cmd.addHelpOption();

    QCommandLineOption inputdir(QStringList() << "d" << "dir",
                                QCoreApplication::translate("main", "dir path ( /path/to/files/ )"),
                                QCoreApplication::translate("main", "dirname"), "");

    QCommandLineOption format(QStringList() << "f" << "format",
                              QCoreApplication::translate("main", "Output format, valid options: txt todotxt, markdown"),
                              QCoreApplication::translate("main", "style"), "");

    QCommandLineOption output(QStringList() << "o" << "output",
                              QCoreApplication::translate("main", "outputfile ( /path/to/output | gist)"),
                              QCoreApplication::translate("main", "outputfile"), "");

    QCommandLineOption gistopt(QStringList() << "g" << "gist",
                               QCoreApplication::translate("main", "Desription for your gist"),
                               QCoreApplication::translate("main", "gist description"), "");

    QCommandLineOption tempopt(QStringList() << "t" << "template",
                               QCoreApplication::translate("main", "template in json format"),
                               QCoreApplication::translate("main", "template"), "");

    cmd.addOption(inputdir);
    cmd.addOption(format);
    cmd.addOption(output);
    cmd.addOption(gistopt);
    cmd.process(a);


    QString srcdir = cmd.value(inputdir);
    QString fmt = cmd.value(format);
    QString outfile = cmd.value(output);
    QString gistdesc = cmd.value(gistopt);

    if(srcdir != ""){
        //@todo replace hardcoded filter...
        QStringList filter(QStringList() << ".cpp" << ".h" << ".java");
        QStringList result = fileLister.listFiles(srcdir, filter);
        QStringList formated;
        for(int i=0; i<result.size(); i++){
            QFileInfo info = QFile(result.at(i));
            parser.setTag(info.fileName());
            QStringList fromfile = fileReader.getLines(result.at(i));

            //@todo improve this part....
            if(fmt.trimmed().toLower()=="txt"){
                formated.append(formatter.plainText(parser.getTask(fromfile)));
            }else if(fmt.trimmed().toLower()=="markdown"){
                formated.append(formatter.markDown(parser.getTask(fromfile)));
            }else if(fmt.trimmed().toLower()=="todotxt"){
                formated.append(formatter.todoText(parser.getTask(fromfile)));
            }else{
                formated.append(formatter.plainText(parser.getTask(fromfile)));
            }
        }
        todo::OutputManager om;
        if(outfile == ""){
            om.stdout(formated);
        }else if( outfile == "gist"){
            QString filePath=QDir::home().absolutePath();
            filePath.append("/.tdlm/oauth");
            QStringList list = fileReader.getLines(filePath);
            QString oauth = list[0];
            client.setOauth(oauth);
            Github::Gist gist;
            gist.setDesription(gistdesc);
            QString content;
            for(int j =0; j < formated.size(); j++){
                content.append(formated.at(j));
                content.append('\n');
            }
            gist.setContent(content);
            client.post(gist.getGistObject());
        }else{
            om.tofile(formated, outfile);
        }
    }
    return a.exec();
}

