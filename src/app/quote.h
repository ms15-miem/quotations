#ifndef QUOTE_H
#define QUOTE_H

#include <QString>

class Quote
{
public:
    Quote(const QString &quoteText);
    QString getText() const;
private:
    QString text;
};

#endif // QUOTE_H
