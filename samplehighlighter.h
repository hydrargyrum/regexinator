#ifndef SAMPLEHIGHLIGHTER_H
#define SAMPLEHIGHLIGHTER_H

#include <QTextEdit>
#include <QRegExp>

class SampleHighlighter : public QTextEdit {
    Q_OBJECT

public:
    explicit SampleHighlighter(QWidget *parent = 0);

public slots:
    void doHighlight(const QRegExp &re);

private:
    QString escapeHtml(QString text);
};

#endif // SAMPLEHIGHLIGHTER_H
