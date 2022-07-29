#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int d, m, y;
    mutable int count;
    static int howmany;

public:
    Date(int = 1, int = 1, int = 2000);
    ~Date(); // In-class

    int get_day() const { return d; }
    int get_month() const { return m; }
    int get_year() const { return y; }
    int get_count() const { return count; }
    void print() const;

    static int how_many_instances() { return howmany; }

    Date &set_day(int);
    Date &set_month(int);
    Date &set_year(int);
};
#endif

#ifndef LINK_H
#define LINK_H
// classe com alaocão dinamica
class Link
{
private:
    Link *back;
    Link *next;
    int item;

public:
    // construtor
    Link(Link *b, Link *n, int i) : back{b}, next{n}, item{i} {}

    // insere antes deste(de this)
    Link *insert(int x)
    {
        return back = new Link{back, this, x};
    }
};
#endif