#ifndef INCORRECTSETTINGSEXCEPTION_H
#define INCORRECTSETTINGSEXCEPTION_H

#include <stdexcept>

class QString;


class IncorrectSettingsException : std::runtime_error
{
public:
    IncorrectSettingsException(const QString &message);

    const char* what() const noexcept override;
};

#endif // INCORRECTSETTINGSEXCEPTION_H
