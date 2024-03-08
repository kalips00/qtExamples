#pragma once

#include <QObject>
#include <QQmlEngine>

#include "entity/RecipeListModel.h"

class RecipeManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(RecipeListModel* recipeModel READ recipeModel WRITE setRecipeModel NOTIFY recipeModelChanged FINAL)

   public:
    explicit RecipeManager(QObject *parent = nullptr);

    RecipeListModel *recipeModel() const;
    void setRecipeModel(RecipeListModel *newRecipeModel);

    Q_INVOKABLE void remove(int index);

   signals:

    void recipeModelChanged();
   private:
    RecipeListModel *_recipeModel = nullptr;
};
