#include <QString>
#include <QStringList>
#include <QtTest>

#include "todo_core/task.h"
#include "todo_core/todoparser.h"
#include "todo_core/textformatter.h"

/**
 * @brief The GaSiProMoTest class, UnitTest for tdlm
 * @note utils are mostly excluded from this tests.
 */
class GaSiProMoTest : public QObject
{
    Q_OBJECT
public:
    GaSiProMoTest();

private Q_SLOTS:
    void testCaseParserOneLine();
    void testCaseParserAllRules();

    void testCaseFormaterPlainText();
    void testCaseFormaterTodoText();
    void testCaseFormaterMarkdown();
};

GaSiProMoTest::GaSiProMoTest(){
}



/**
 * @brief GaSiProMoTest::testCaseParserOneLine, basic test
 */
void GaSiProMoTest::testCaseParserOneLine(){
    QString matchString = "do something.";

    QStringList testdata;
    testdata.append("/**@todo do something. */");

    todo::TodoParser parser;
    QVector<todo::Task>task = parser.getTask(testdata);
    QCOMPARE(task.at(0).description, matchString);
}

/**
 * @brief GaSiProMoTest::testCaseParserAllRules, testing all implemented rules
 */
void GaSiProMoTest::testCaseParserAllRules(){
    QString matchString = "do something.";

    QStringList testdata;
    testdata.append("/**@todo do something. */");
    testdata.append("///@todo do something.");
    testdata.append("/* @todo do something. */");
    testdata.append("/** @todo do something. */");
    testdata.append("///TODO do something.");
    testdata.append("/* @note nothing should happen.");

    todo::TodoParser parser;
    QVector<todo::Task>tasks = parser.getTask(testdata);

    for(int i=0; i<tasks.size(); i++){
        QCOMPARE(tasks.at(i).description, matchString);
    }
}

void GaSiProMoTest::testCaseFormaterPlainText(){

    QString matchString = "do something.";
    QString tag="TEST";

    QStringList testdata;
    testdata.append("/**@todo do something. */");
    testdata.append("///@todo do something.");
    testdata.append("/* @todo do something. */");
    testdata.append("/** @todo do something. */");
    testdata.append("///TODO do something.");
    testdata.append("/* @note nothing should happen.");

    todo::TodoParser parser;
    todo::TextFormatter formater;

    parser.setTag(tag);
    QVector<todo::Task>tasks = parser.getTask(testdata);

    QStringList formated = formater.plainText(tasks);

    for(int i=0; i<formated.size(); i++){
        QString comp;
        comp.append(matchString);
        comp.append(" Tag:");
        comp.append(tag);
        comp.append(" Line:");
        comp.append(QString::number(i+1)); //Files start at line 1
        QCOMPARE(formated.at(i), comp);
    }
}

void GaSiProMoTest::testCaseFormaterTodoText(){

    QString matchString = "do something.";
    QString tag="TEST";

    QStringList testdata;
    testdata.append("/**@todo do something. */");
    testdata.append("///@todo do something.");
    testdata.append("///@todo Auto-generated.");

    todo::TodoParser parser;
    todo::TextFormatter formater;

    parser.setTag(tag);
    QVector<todo::Task>tasks = parser.getTask(testdata);

    QStringList formated = formater.todoText(tasks);

    QCOMPARE(formated.at(0), QString("(A) Line:1 do something. @TEST"));
    QCOMPARE(formated.at(1), QString("(A) Line:2 do something. @TEST"));
    QCOMPARE(formated.at(2), QString("(D) Line:3 Auto-generated. @TEST +cleanup"));
}

void GaSiProMoTest::testCaseFormaterMarkdown(){

    QStringList testdata;
    testdata.append("/**@todo do something. */");
    testdata.append("///@todo do something.");
    testdata.append("///@todo Auto-generated.");

    todo::TodoParser parser;
    todo::TextFormatter formater;

    parser.setTag("TEST");
    QVector<todo::Task>tasks = parser.getTask(testdata);

    QStringList formated = formater.markDown(tasks);

    QCOMPARE(formated.at(0), QString("- [ ] Line:1 do something. **TEST**"));
    QCOMPARE(formated.at(1), QString("- [ ] Line:2 do something. **TEST**"));
    QCOMPARE(formated.at(2), QString("- [ ] Line:3 Auto-generated. **TEST**"));

}

void GaSiProMoTest::testCaseParseTemplate(){
    QString
}

QTEST_APPLESS_MAIN(GaSiProMoTest)

#include "tst_gasipromotest.moc"
