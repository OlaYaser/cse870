#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <QString>
#include "common.h"

class Checkpoint
{
public:
    Checkpoint();

    accessCode_t checkSecurityPolicy(const QString &username, const QString &password);
};

#endif // CHECKPOINT_H
