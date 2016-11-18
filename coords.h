#ifndef COORDS_H
#define COORDS_H

#include <QTextStream>

class Coords
{
public:
    Coords();

    Coords(int i, int j)
        : i(i), j(j)
    {}

    Coords operator-() const
    {
        return Coords(-i, -j);
    }

    Coords &operator+=(const Coords &other)
    {
        i += other.i;
        j += other.j;

        return *this;
    }

    bool isValid() const
    {
        return isValid(i) && isValid(j);
    }

    int i=-1;
    int j=-1;
private:
    static bool isValid(int i)
    {
        return 0<=i && i<3;
    }
};

inline QTextStream &operator<< (QTextStream& stream, const Coords &coords)
{
    return stream << coords.i << " " << coords.j;
}

inline QTextStream &operator>> (QTextStream& stream, Coords &coords)
{
    return stream >> coords.i >> coords.j;
}

#endif // COORDS_H
