#ifndef MARK_H
#define MARK_H

#include <QTextStream>

enum class Mark {
    None,
    Nought,
    Cross
};

QTextStream &operator<< (QTextStream& stream, Mark mark);
QTextStream &operator>> (QTextStream& stream, Mark &mark);

#endif // MARK_H
