#pragma once

#include <QObject>

#include "Recipe.h"

class Chef : public QObject
{
    Q_OBJECT
   public:
    explicit Chef(QObject *parent = nullptr);
    ~Chef();

   signals:
    void beginRecipePreparation();
    void putRecipeInOven(const OvenConfiguration &ovenConfiguration);
};
