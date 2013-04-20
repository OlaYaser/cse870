#ifndef SINGLEACCESSPOINT_H
#define SINGLEACCESSPOINT_H

#include <QList>
#include "common.h"
#include "object.h"
#include "checkpoint.h"

class SingleAccessPoint
{
    Checkpoint* m_checkpoint;

public:
    SingleAccessPoint(Checkpoint *);

signals:
    
public slots:
    actionCode_t access(const QString &username, const QString &password, accessCode_t &accessCode, const QList<Object> &objects, int& index);

};

#endif // SINGLEACCESSPOINT_H
