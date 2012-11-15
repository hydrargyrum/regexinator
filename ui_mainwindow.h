/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Nov 15 18:46:19 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "samplehighlighter.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *regexBox;
    QLabel *label_2;
    SampleHighlighter *targetBox;
    QTabWidget *tabWidget;
    QWidget *Controls;
    QCheckBox *chkCaseSensitive;
    QComboBox *cmbPatternSyntax;
    QCheckBox *chkNewLineMode;
    QWidget *Extra;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(319, 491);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        regexBox = new QTextEdit(centralwidget);
        regexBox->setObjectName(QString::fromUtf8("regexBox"));

        verticalLayout->addWidget(regexBox);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        targetBox = new SampleHighlighter(centralwidget);
        targetBox->setObjectName(QString::fromUtf8("targetBox"));

        verticalLayout->addWidget(targetBox);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 200));
        Controls = new QWidget();
        Controls->setObjectName(QString::fromUtf8("Controls"));
        chkCaseSensitive = new QCheckBox(Controls);
        chkCaseSensitive->setObjectName(QString::fromUtf8("chkCaseSensitive"));
        chkCaseSensitive->setGeometry(QRect(164, 10, 121, 20));
        cmbPatternSyntax = new QComboBox(Controls);
        cmbPatternSyntax->setObjectName(QString::fromUtf8("cmbPatternSyntax"));
        cmbPatternSyntax->setGeometry(QRect(167, 50, 111, 24));
        chkNewLineMode = new QCheckBox(Controls);
        chkNewLineMode->setObjectName(QString::fromUtf8("chkNewLineMode"));
        chkNewLineMode->setGeometry(QRect(164, 30, 111, 20));
        tabWidget->addTab(Controls, QString());
        Extra = new QWidget();
        Extra->setObjectName(QString::fromUtf8("Extra"));
        tabWidget->addTab(Extra, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 319, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(regexBox, SIGNAL(selectionChanged()), MainWindow, SLOT(compileSelectedRegex()));
        QObject::connect(regexBox, SIGNAL(textChanged()), MainWindow, SLOT(compileRegex()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Regular Expression:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Target:", 0, QApplication::UnicodeUTF8));
        chkCaseSensitive->setText(QApplication::translate("MainWindow", "Case-Sensitive", 0, QApplication::UnicodeUTF8));
        cmbPatternSyntax->clear();
        cmbPatternSyntax->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "RegExp", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "RegExp2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Wildcard", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WildcardUnix", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "FixedString", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "W3CXmlSchema11", 0, QApplication::UnicodeUTF8)
        );
        chkNewLineMode->setText(QApplication::translate("MainWindow", "Newline Mode", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Controls), QApplication::translate("MainWindow", "Controls", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Extra), QApplication::translate("MainWindow", "Extra", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
