#include "RecipeManager.h"

RecipeManager::RecipeManager(QObject *parent)
    : QObject{parent}
{
    _recipeModel = new RecipeListModel();

    auto recipe1 = new Recipe(_recipeModel);
    recipe1->setTitle("Gâteau au chocolat");
        recipe1->setcontent("Un contenu pour le gâteau au chocolat ");
        recipe1->setDifficulty(2);
    recipe1->setPreparationDuration(55);

    auto recipe2 = new Recipe(_recipeModel);
    auto ovenConf = new OvenConfiguration(55, 25, recipe2);

    recipe2->setTitle("Salade de fruit");
    recipe2->setcontent("Un contenu pour la salade de fruit");
    recipe2->setDifficulty(0);
    recipe2->setPreparationDuration(25);
    recipe2->setOvenConfiguration(ovenConf);

    _recipeModel->append(recipe1);
    _recipeModel->append(recipe2);
}

RecipeListModel *RecipeManager::recipeModel() const
{
    return _recipeModel;
}

void RecipeManager::setRecipeModel(RecipeListModel *newRecipeModel)
{
    if (_recipeModel == newRecipeModel)
        return;
    _recipeModel = newRecipeModel;
    emit recipeModelChanged();
}

void RecipeManager::remove(int index)
{
    if(_recipeModel != nullptr && index >= 0 && index < _recipeModel->count())
    {
        qDebug() << "User ask element removal.";
        _recipeModel->remove(index);
    }
}
