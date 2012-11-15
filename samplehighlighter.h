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
	void doMultiHighlight(const QRegExp &re);
private:
	QString highlight(const QString &text, const QRegExp re);
    QString escapeHtml(QString text);
};

#endif // SAMPLEHIGHLIGHTER_H
