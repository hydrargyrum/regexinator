#include "mainwindow.h"

MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent), parent(parent), ui(new Ui_MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::compileSelectedRegex() {
    QRegExp re = CreateRegExp(ui->regexBox->textCursor().selectedText());
    if (re.indexIn(ui->targetBox->toPlainText()))
        qDebug() << re.capturedTexts();
}

void MainWindow::compileRegex() {
    QRegExp re = CreateRegExp(ui->regexBox->toPlainText());
    ui->targetBox->doHighlight(re);
}


QRegExp MainWindow::CreateRegExp(QString text) {
    QRegExp re;
    if (ui->chkCaseSensitive->isChecked())
        re = QRegExp(text, Qt::CaseSensitive);
    else
        re = QRegExp(text, Qt::CaseInsensitive);

    re.setPatternSyntax((QRegExp::PatternSyntax) ui->cmbPatternSyntax->currentIndex());
    return re;
}
