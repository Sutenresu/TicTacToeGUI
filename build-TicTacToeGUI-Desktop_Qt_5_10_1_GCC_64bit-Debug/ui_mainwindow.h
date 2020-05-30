/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *button00;
    QPushButton *button22;
    QPushButton *button12;
    QPushButton *button02;
    QPushButton *button21;
    QPushButton *button11;
    QPushButton *button01;
    QPushButton *button20;
    QPushButton *button10;
    QTextBrowser *textBrowser;
    QTextBrowser *mainText;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QPushButton *buttonRetry;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(419, 345);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        button00 = new QPushButton(centralWidget);
        button00->setObjectName(QStringLiteral("button00"));
        button00->setGeometry(QRect(20, 90, 51, 51));
        QFont font;
        font.setPointSize(24);
        button00->setFont(font);
        button22 = new QPushButton(centralWidget);
        button22->setObjectName(QStringLiteral("button22"));
        button22->setGeometry(QRect(160, 230, 51, 51));
        button22->setFont(font);
        button12 = new QPushButton(centralWidget);
        button12->setObjectName(QStringLiteral("button12"));
        button12->setGeometry(QRect(90, 230, 51, 51));
        button12->setFont(font);
        button02 = new QPushButton(centralWidget);
        button02->setObjectName(QStringLiteral("button02"));
        button02->setGeometry(QRect(20, 230, 51, 51));
        button02->setFont(font);
        button21 = new QPushButton(centralWidget);
        button21->setObjectName(QStringLiteral("button21"));
        button21->setGeometry(QRect(160, 160, 51, 51));
        button21->setFont(font);
        button11 = new QPushButton(centralWidget);
        button11->setObjectName(QStringLiteral("button11"));
        button11->setGeometry(QRect(90, 160, 51, 51));
        button11->setFont(font);
        button01 = new QPushButton(centralWidget);
        button01->setObjectName(QStringLiteral("button01"));
        button01->setGeometry(QRect(20, 160, 51, 51));
        button01->setFont(font);
        button20 = new QPushButton(centralWidget);
        button20->setObjectName(QStringLiteral("button20"));
        button20->setGeometry(QRect(160, 90, 51, 51));
        button20->setFont(font);
        button10 = new QPushButton(centralWidget);
        button10->setObjectName(QStringLiteral("button10"));
        button10->setGeometry(QRect(90, 90, 51, 51));
        button10->setFont(font);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 20, 381, 41));
        mainText = new QTextBrowser(centralWidget);
        mainText->setObjectName(QStringLiteral("mainText"));
        mainText->setGeometry(QRect(230, 90, 171, 151));
        QFont font1;
        font1.setPointSize(11);
        mainText->setFont(font1);
        mainText->setLineWrapMode(QTextEdit::WidgetWidth);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 210, 191, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(20, 140, 191, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(70, 90, 20, 191));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(140, 90, 20, 191));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        buttonRetry = new QPushButton(centralWidget);
        buttonRetry->setObjectName(QStringLiteral("buttonRetry"));
        buttonRetry->setGeometry(QRect(230, 250, 171, 31));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        buttonRetry->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 419, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        button00->setText(QString());
        button22->setText(QString());
        button12->setText(QString());
        button02->setText(QString());
        button21->setText(QString());
        button11->setText(QString());
        button01->setText(QString());
        button20->setText(QString());
        button10->setText(QString());
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600;\">Tic Tac Toe</span></p></body></html>", nullptr));
        mainText->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p></body></html>", nullptr));
        buttonRetry->setText(QApplication::translate("MainWindow", "Restart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
