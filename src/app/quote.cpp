#include "quote.h"

Quote::Quote(QString &quoteText):text(quoteText)
{
}

QString Quote::getText() const
{
    return text;
}
