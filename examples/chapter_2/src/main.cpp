#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "entity/RecipeListModel.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/chapter_2/src/qml/Main.qml"_qs);

    RecipeListModel* model = new RecipeListModel();

    auto recipe1 = new Recipe(model);
    recipe1->setTitle("Gâteau au chocolat");
    recipe1->setcontent("Un contenu pour le gâteau au chocolat ");
    recipe1->setDifficulty(2);
    recipe1->setPreparationDuration(55);

    auto recipe2 = new Recipe(model);
    auto ovenConf = new OvenConfiguration(55, 25, recipe2);

    recipe2->setTitle("Salade de fruit");
    recipe2->setcontent("Un contenu pour la salade de fruit");
    recipe2->setDifficulty(0);
    recipe2->setPreparationDuration(25);
    recipe2->setOvenConfiguration(ovenConf);

    model->append(recipe1);
    model->append(recipe2);

    engine.rootContext()->setContextProperty("ctx_model", model);

    engine.load(url);

    auto exitCode = app.exec();

    model->deleteLater();

    return exitCode;
}
