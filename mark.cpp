#include "mark.h"

QString mark2str(Mark mark)
{
    switch (mark) {
    case Mark::Cross: return "x";
    case Mark::Nought: return "o";
    case Mark::None: return "_";
    }

    return QString();
}

Mark str2mark(const QString& str)
{
    if (str == "x")
        return Mark::Cross;
    if (str == "o")
        return Mark::Nought;
    if (str == "_")
        return Mark::None;

    return Mark::None;
}


QTextStream &operator<<(QTextStream &stream, Mark mark)
{
    return stream << mark2str(mark);
}

QTextStream &operator>>(QTextStream &stream, Mark &mark)
{
    QString tmp;
    stream >> tmp;

    mark = str2mark(tmp);

    return stream;
}
