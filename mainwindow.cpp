#include "mainwindow.h"

MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent), parent(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::compileSelectedRegex() {
    QRegExp re(ui->regexBox->textCursor().selectedText());
    if (re.indexIn(ui->targetBox->toPlainText()))
        qDebug() << re.capturedTexts();
}
