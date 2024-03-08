#include <QDateTime>
#include <QDebug>
#include <QList>
#include <QObject>
#include <QRegularExpression>
#include <QTimer>
#include <QVariant>

#include "Chef.h"
#include "Recipe.h"

void basicObjectUsage()
{
    qDebug() << "===================================";
    qDebug() << Q_FUNC_INFO;
    qDebug() << "====";

    QObject parent;
    parent.setObjectName("RecettesCuisine");

    QObject recipe1(&parent);
    recipe1.setObjectName("Lasagnes");
    recipe1.setProperty("difficulté", "Facile");
    recipe1.setProperty("durée", "30 minutes");

    QObject recipe2(&parent);
    recipe2.setObjectName("Tiramisu");
    recipe2.setProperty("difficulté", "Moyen");
    recipe2.setProperty("duree", "20 minutes");

    qDebug() << "Recette 1 : " << recipe1.objectName();
    qDebug() << "   Difficulté : " << recipe1.property("difficulté");
    qDebug() << "   Temps de préparation : " << recipe1.property("durée");

    qDebug() << "Recette 2 : " << recipe2.objectName();
    qDebug() << "   Difficulté : " << recipe2.property("difficulté");
    qDebug() << "   Temps de préparation : " << recipe2.property("durée");
}

void basicStringUsage()
{
    qDebug() << "===================================";
    qDebug() << Q_FUNC_INFO;
    qDebug() << "====";

    QString str1 = "Hello";
    QString str2 = "World";
    QString result = str1 + " " + str2;
    qDebug() << result;

    auto hello = result.left(5);
    qDebug() << hello;

    auto world = result.right(5);
    qDebug() << world;

    qDebug() << world.contains("orl");
}

void basicListUsage()
{
    qDebug() << "===================================";
    qDebug() << Q_FUNC_INFO;
    qDebug() << "====";

    QList<QString> stringList;
    stringList << "element 1"
               << "element 2";
    qDebug() << stringList;

    for (const auto& element : stringList)
    {
        qDebug() << "Element: " << element;
    }

    QList<int> intList({1, 2, 3, 4, 5, 6, 7, 8});
    qDebug() << intList;

    for (auto element : intList)
    {
        qDebug() << "Element: " << element;
    }
}

void basicDateUsage()
{
    qDebug() << "===================================";
    qDebug() << Q_FUNC_INFO;
    qDebug() << "====";

    QDateTime currentDateTime = QDateTime::currentDateTime();
    qDebug() << "Date courante:" << currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    qDebug() << "Jour:" << currentDateTime.date().day();
    qDebug() << "Annee:" << currentDateTime.date().year();
}

void basicSignalSlotsCommunication()
{
    qDebug() << "===================================";
    qDebug() << Q_FUNC_INFO;
    qDebug() << "====";

    Recipe recipe;
    Chef chef;

    // connections
    QObject::connect(&chef, &Chef::beginRecipePreparation, &recipe, &Recipe::onPrepared);
    QObject::connect(&chef, &Chef::putRecipeInOven, &recipe, &Recipe::onPutIntoOven);

    // emit signals
    emit chef.beginRecipePreparation();
    emit chef.putRecipeInOven({180, 20});
}

void basicGarbageCollectorMecanism()
{
    qDebug() << "===================================";
    qDebug() << Q_FUNC_INFO;
    qDebug() << "====";

    Chef* chef = new Chef();
    Recipe* recipe = new Recipe(chef);
    Q_UNUSED(recipe)

    // should call recipe destructor
    chef->deleteLater();
}
int main(int argc, char* argv[])
{
    basicObjectUsage();
    basicStringUsage();
    basicListUsage();
    basicDateUsage();
    basicSignalSlotsCommunication();
    basicGarbageCollectorMecanism();
    return 0;
}
