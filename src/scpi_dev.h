#ifndef SCPI_DEV_H
#define SCPI_DEV_H

#include "qserial.h"
#include <qlist.h>
#include <qstringlist.h>

class ScpiDev : protected QSerial
{
public:
    typedef const char *Sense_t;
    typedef int Channel_t;
    typedef QList<Channel_t> Channels_t;
    Channels_t routeChannelsClosed;

    static Sense_t SenseVolt;
    static Sense_t SenseRes;

    ScpiDev();
    ~ScpiDev();
    void close();
    double current();
    void init();
    bool open(const QString &port, BaudeRate_t baudeRate = QSerial::Baude9600);
    bool output();
    QStringList read();
    void setCurrent(double current);
    void setOutput(bool enabled);
    void setRoute(Channels_t closeChannels);
    void setScan(Channel_t channel);
    void setScan(Channels_t channels);
    void setSense(Sense_t sense, Channels_t channels);

protected:
    QString formatCmd(const QString &cmd, const Channels_t &channels);
    void sendCmd(const QString &cmd, long timeout = 0);
    void sendCmd(const QString &cmd, const Channels_t &channels, long timeout = 0);
    QString sendQuery(const QString &cmd, long timeout = 0);
    QString sendQuery(const QString &cmd, const Channels_t &channels, long timeout = 0);

private:

};

#endif // SCPI_DEV_H
