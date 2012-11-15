#include "samplehighlighter.h"

#include <QDebug>

SampleHighlighter::SampleHighlighter(QWidget *parent) :
    QTextEdit(parent)
{
}

void SampleHighlighter::doHighlight(const QRegExp &re) {
	setHtml(highlight(this->toPlainText(), re));
}

void SampleHighlighter::doMultiHighlight(const QRegExp &re) {
	QString ss;
	QTextStream s(&ss);
	QStringList sl = this->toPlainText().split("\n");
	for (int x = 0; x < sl.size(); ++x) {
		s << QString("%1<br />").arg(highlight(sl[x], re));
	}
	setHtml(*s.string());
}

QString SampleHighlighter::highlight(const QString &text, const QRegExp re) {
    if (re.indexIn(text) >= 0) {
        QString htmlTemplate = "%1<font color=\"red\">%2</font>%3";
        QString beforeText = text.left(re.pos()),
                matchedText = text.mid(re.pos(), re.matchedLength()),
                afterText = text.mid(re.pos() + re.matchedLength());

		return htmlTemplate.arg(escapeHtml(beforeText), escapeHtml(matchedText), escapeHtml(afterText));
    } else {
        return text;
	}
}

QString SampleHighlighter::escapeHtml(QString text) {
    return text.replace('&', "&amp;").replace('<', "&lt;").replace('>', "&gt;");
}
