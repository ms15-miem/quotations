#include "quote.h"

Quote::Quote(const QString &quoteText):text(quoteText)
{
}

QString Quote::getText() const
{
    return text;
}
