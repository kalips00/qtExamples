#pragma once

#include <QObject>

class OvenConfiguration
{
   public:
    OvenConfiguration(int pTemperature, int pDuration) : temperature(pTemperature), duration(pDuration){};

    int temperature;
    int duration;
};

class Recipe : public QObject
{
    Q_OBJECT
   public:
    enum Difficulty
    {
        EASY,
        MEDIUM,
        HARD
    };

    explicit Recipe(QObject* parent = nullptr);
    ~Recipe();

   signals:

   public slots:
    void onPrepared();
    void onPutIntoOven(const OvenConfiguration& ovenConfiguration);

   private:
    QString title;
    int preparationDuration{0};
    Difficulty difficulty{Difficulty::EASY};
};
