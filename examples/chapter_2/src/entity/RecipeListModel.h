#pragma once

#include <QAbstractListModel>
#include <QObject>

#include "Recipe.h"

class RecipeListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("Not instanciable in Qml")

    Q_PROPERTY(int count READ count NOTIFY countChanged FINAL)

   public:
    explicit RecipeListModel(QObject *parent = nullptr);

    enum RecipeRoles
    {
        Title = Qt::UserRole + 1,
        Content,
        Difficulty,
        PreparationDuration,
        OvenConfiguration
    };

    // accessors
    int count();

    // parent override
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void append(Recipe *reciped);
    void remove(int index);

   signals:
    void countChanged();

   private:
    QList<Recipe *> _recipeList;
};
