#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QTranslator>
#include <QString>
#include <unordered_map>
#include "Language.hh"


class Translator
{
public:
    Translator();

    void loadTranslation(Language language);

private:
    QTranslator translator;


    QString getTranslationFile(Language language) const;
};

#endif // TRANSLATOR_H
