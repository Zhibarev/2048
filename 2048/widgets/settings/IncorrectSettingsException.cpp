#include "IncorrectSettingsException.hh"

IncorrectSettingsException::IncorrectSettingsException(const QString &message)
    : std::runtime_error(message.toStdString())
{

}

const char *IncorrectSettingsException::what() const noexcept
{
    return std::runtime_error::what();
}
