#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

#include "ui_mainwindow.h"

class MainWindow :
    public QMainWindow {

    Q_OBJECT

public:
    explicit MainWindow(QMainWindow *parent = 0);
    virtual ~MainWindow() {}

private slots:
    void compileSelectedRegex();
	void compileRegex();

private:
    QWidget *parent;
    Ui_MainWindow *ui;
};
#endif
