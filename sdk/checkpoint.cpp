#include "checkpoint.h"

Checkpoint::Checkpoint()
{

}

accessCode_t Checkpoint::checkSecurityPolicy(const QString& username, const QString& password)
{
    if (username.compare("Root", Qt::CaseInsensitive) == 0) {
        if (password.compare("admin") == 0) return ROOT;
    }
    else if (username.compare("Driver") == 0) {
        if (password.compare("gear") == 0) return DRIVER;
    }

    return INTRUDER;
}
