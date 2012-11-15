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

void MainWindow::compileRegex() {
    QRegExp re(ui->regexBox->toPlainText());
    ui->targetBox->doHighlight(re);
}
