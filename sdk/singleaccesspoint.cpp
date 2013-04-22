#include "singleaccesspoint.h"

SingleAccessPoint::SingleAccessPoint(Checkpoint *checkpoint)
{
    m_checkpoint = checkpoint;
}

actionCode_t SingleAccessPoint::access(const QString &username, const QString &password, accessCode_t &accessCode, const QList<Object> &objects, int& index)
{
    // Ask checkpoint for access
    accessCode = m_checkpoint->checkSecurityPolicy(username, password);

    actionCode_t actionCode = NOTHING;

    if (accessCode != INTRUDER) actionCode = Monitor::GetInstance().newObjects(objects, index);

    return actionCode;
}
