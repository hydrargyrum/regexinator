#include "samplehighlighter.h"

SampleHighlighter::SampleHighlighter(QWidget *parent) :
    QTextEdit(parent)
{
}

void SampleHighlighter::doHighlight(const QRegExp &re) {
    QString text = this->toPlainText();

    if (re.indexIn(text) >= 0) {
        QString htmlTemplate = "%1<font color=\"red\">%2</font>%3";
        QString beforeText = text.left(re.pos()),
                matchedText = text.mid(re.pos(), re.matchedLength()),
                afterText = text.mid(re.pos() + re.matchedLength());

        setHtml(htmlTemplate.arg(escapeHtml(beforeText), escapeHtml(matchedText), escapeHtml(afterText)));
    } else
        setPlainText(text);
}

QString SampleHighlighter::escapeHtml(QString text) {
    return text.replace('&', "&amp;").replace('<', "&lt;").replace('>', "&gt;");
}
