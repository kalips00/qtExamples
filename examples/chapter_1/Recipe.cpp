#include "Recipe.h"

#include <QDebug>

Recipe::Recipe(QObject *parent) : QObject{parent} {}

Recipe::~Recipe() { qDebug() << "Recipe is deleted !!"; }

void Recipe::onPrepared() { qDebug() << "Début de la préparation de la recette..."; }

void Recipe::onPutIntoOven(const OvenConfiguration &ovenConfiguration)
{
    qDebug() << "Mettre au four";
    qDebug() << "Configuration:";
    qDebug() << "   temperature:" << ovenConfiguration.temperature;
    qDebug() << "   durée:" << ovenConfiguration.duration;
}
