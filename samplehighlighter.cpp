#include "samplehighlighter.h"

#include <QDebug>

SampleHighlighter::SampleHighlighter(QWidget *parent) :
    QTextEdit(parent)
{
}

void SampleHighlighter::setHtml(const QString &text) {
    // ugly hack: QTextEdit::setHtml emits textChanged so it becomes recursive
    bool previouslyBlocked = signalsBlocked();
    if (!previouslyBlocked)
        blockSignals(true);

    // keep cursor position
    int cursorPos = textCursor().position();
    QTextEdit::setHtml(text);
    QTextCursor cursor = textCursor();
    cursor.setPosition(cursorPos);
    setTextCursor(cursor);

    if (!previouslyBlocked)
        blockSignals(false);
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

QString SampleHighlighter::captureColor(int capture) {
    QStringList colors;
    colors << "orange" << "green" << "blue" << "indigo" << "violet";
    return capture ? colors[(capture - 1) % colors.length()] : "red";
}

QString SampleHighlighter::highlight(const QString &text, const QRegExp re) {
    if (re.indexIn(text) >= 0) {
        // generate the html tags to insert at index N
        // the captures work as a stack, so do the html styling tags
        QMap<int, QString> tags;
        for (int i = 0; i <= re.captureCount(); i++) {
            if (re.cap(i).isEmpty())
                continue; // this case is tricky else
            tags[re.pos(i)].append(QString("<font color=\"%1\">").arg(captureColor(i)));
            tags[re.pos(i) + re.cap(i).length()].prepend(QString("</font>"));
        }

        // interlace text and tags for building final html
        QStringList parts;
        int currentPos = 0;
        foreach (int pos, tags.keys()) {
            parts << escapeHtml(text.mid(currentPos, pos - currentPos));
            parts << tags[pos];
            currentPos = pos;
        }
        parts << escapeHtml(text.mid(currentPos));

        return parts.join("");
    } else {
        QString htmlTemplate = "<font color=\"grey\">%1</font>";
        return htmlTemplate.arg(escapeHtml(text));
	}
}

QString SampleHighlighter::escapeHtml(QString text) {
    return text.replace('&', "&amp;").replace('<', "&lt;").replace('>', "&gt;").replace('\n', "<br/>");
}
