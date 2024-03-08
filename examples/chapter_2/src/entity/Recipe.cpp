#include "Recipe.h"

#include <QDebug>

OvenConfiguration::OvenConfiguration(int temperature, int duration, QObject *parent)
    : QObject(parent), _temperature(temperature), _duration(duration)
{
}

Recipe::Recipe(QObject *parent) : QObject{parent} {}

Recipe::~Recipe() { qDebug() << "Recipe is deleted !!"; }

void Recipe::onPrepared() { qDebug() << "Début de la préparation de la recette..."; }

void Recipe::onPutIntoOven(const OvenConfiguration &ovenConfiguration)
{
    if (_ovenConfiguration != nullptr)
    {
        qDebug() << "Mettre au four";
        qDebug() << "Configuration:";
        qDebug() << "   temperature:" << _ovenConfiguration->temperature();
        qDebug() << "   durée:" << _ovenConfiguration->duration();
    }
}

int OvenConfiguration::duration() const { return _duration; }

void OvenConfiguration::setDuration(int newDuration)
{
    if (_duration == newDuration)
    {
        return;
    }
    _duration = newDuration;
    emit durationChanged();
}

int OvenConfiguration::temperature() const { return _temperature; }

void OvenConfiguration::setTemperature(int newTemperature)
{
    if (_temperature == newTemperature)
    {
        return;
    }
    _temperature = newTemperature;
    emit temperatureChanged();
}

QString Recipe::title() const { return _title; }

void Recipe::setTitle(const QString &newTitle)
{
    if (_title == newTitle) return;
    _title = newTitle;
    emit titleChanged();
}

QString Recipe::content() const { return _content; }

void Recipe::setcontent(const QString &newContent)
{
    if (_content == newContent)
    {
        return;
    }
    _content = newContent;
    emit contentChanged();
}

int Recipe::difficulty() const { return static_cast<int>(_difficulty); }

void Recipe::setDifficulty(int newDifficulty)
{
    if (_difficulty == static_cast<Difficulty>(newDifficulty))
    {
        return;
    }
    _difficulty = Difficulty(newDifficulty);
    emit difficultyChanged();
}

int Recipe::preparationDuration() const { return _preparationDuration; }

void Recipe::setPreparationDuration(int newpreparationDuration)
{
    if (_preparationDuration == newpreparationDuration)
    {
        return;
    }
    _preparationDuration = newpreparationDuration;
    emit preparationDurationChanged();
}

OvenConfiguration *Recipe::ovenConfiguration() const { return _ovenConfiguration; }

void Recipe::setOvenConfiguration(OvenConfiguration *newOvenConfiguration)
{
    if (_ovenConfiguration == newOvenConfiguration)
    {
        return;
    }
    _ovenConfiguration = newOvenConfiguration;
    emit ovenConfigurationChanged();
}
