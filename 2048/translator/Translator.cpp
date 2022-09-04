#include "Translator.hh"
#include <QApplication>

Translator::Translator()
{
    loadTranslation(Language::ENGLISH);
    qApp->installTranslator(&translator);
}

void Translator::loadTranslation(Language language) {
    QString translationFile = getTranslationFile(language);

    if (!translator.load(translationFile))
        qFatal("Translation file \"%s\" not found", qPrintable(translationFile));
}

QString Translator::getTranslationFile(Language language) const {
    switch (language) {
        case Language::FINISH:
            return "resources/QtLanguage_fi";
        break;
        case Language::ENGLISH:
            return "resources/QtLanguage_en";
        break;
        default:
            qFatal("Unrealized translation");
    }
}
