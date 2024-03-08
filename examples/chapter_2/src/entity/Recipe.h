#pragma once

#include <QObject>
#include <QtQmlIntegration/QtQmlIntegration>

class OvenConfiguration : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("Not instanciable in Qml")

    Q_PROPERTY(int temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged FINAL)
    Q_PROPERTY(int duration READ duration WRITE setDuration NOTIFY durationChanged FINAL)

   public:
    OvenConfiguration(int temperature, int duration, QObject *parent = nullptr);

    // accessors
    int duration() const;
    void setDuration(int newDuration);

    int temperature() const;
    void setTemperature(int newTemperature);

   signals:
    void durationChanged();
    void temperatureChanged();

   private:
    int _temperature;
    int _duration;
};

class Recipe : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("Not instanciable in Qml")

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
    Q_PROPERTY(QString content READ content WRITE setcontent NOTIFY contentChanged FINAL)
    Q_PROPERTY(int difficulty READ difficulty WRITE setDifficulty NOTIFY difficultyChanged FINAL)
    Q_PROPERTY(int preparationDuration READ preparationDuration WRITE setPreparationDuration NOTIFY
                   preparationDurationChanged FINAL)
    Q_PROPERTY(OvenConfiguration *ovenConfiguration READ ovenConfiguration WRITE setOvenConfiguration NOTIFY
                   ovenConfigurationChanged FINAL)

   public:
    enum class Difficulty
    {
        EASY,
        MEDIUM,
        HARD
    };
    Q_ENUM(Difficulty)

    explicit Recipe(QObject *parent = nullptr);
    ~Recipe();

    QString title() const;
    void setTitle(const QString &newTitle);

    QString content() const;
    void setcontent(const QString &newContent);

    int difficulty() const;
    void setDifficulty(int newDifficulty);

    int preparationDuration() const;
    void setPreparationDuration(int newpreparationDuration);

    OvenConfiguration *ovenConfiguration() const;
    void setOvenConfiguration(OvenConfiguration *newOvenConfiguration);

   public slots:
    void onPrepared();
    void onPutIntoOven(const OvenConfiguration &ovenConfiguration);

   signals:
    void titleChanged();
    void contentChanged();
    void difficultyChanged();
    void preparationDurationChanged();

    void ovenConfigurationChanged();

   private:
    QString _title;
    QString _content;
    Difficulty _difficulty{Difficulty::EASY};
    int _preparationDuration{};
    OvenConfiguration *_ovenConfiguration{};
};
