
#include <qstringlist.h>
#include "skconfig.h"

unsigned int SkConfig::ip2num(const QString &str_ip)
{
    QStringList var_bytes = str_ip.split(".");
    if (4 != var_bytes.size())
        return 0;
    return var_bytes[3].toInt() | var_bytes[2].toInt() << 8 |
           var_bytes[1].toInt() << 16 | var_bytes[0].toInt() << 24;
}

QString SkConfig::num2ip(const unsigned int val_ip)
{
    return QString("%1.%2.%3.%4")
        .arg((val_ip >> 24) & 0xFF)
        .arg((val_ip >> 16) & 0xFF)
        .arg((val_ip >> 8) & 0xFF)
        .arg(val_ip & 0xFF);
}

int SkConfig::verify(void)
{
    return 0;
}

int ClientConfig::verify(void)
{
    return 0;
}

