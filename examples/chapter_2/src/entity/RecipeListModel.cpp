#include "RecipeListModel.h"

RecipeListModel::RecipeListModel(QObject *parent) : QAbstractListModel{parent}
{
    connect(this, &RecipeListModel::rowsInserted, this, &RecipeListModel::countChanged);
    connect(this, &RecipeListModel::rowsRemoved, this, &RecipeListModel::countChanged);
}

int RecipeListModel::count() { return _recipeList.size(); }

int RecipeListModel::rowCount(const QModelIndex &parent) const { return _recipeList.size(); }

QVariant RecipeListModel::data(const QModelIndex &index, int role) const
{
    auto row = index.row();
    if (!index.isValid() || row < 0 || row >= _recipeList.size())
    {
        return QVariant();
    }

    switch (role)
    {
        case RecipeRoles::Title:
            return _recipeList.at(row)->title();
            break;
        case RecipeRoles::Content:
            return _recipeList.at(row)->content();
            break;
        case RecipeRoles::Difficulty:
            return _recipeList.at(row)->difficulty();
            break;
        case RecipeRoles::PreparationDuration:
            return _recipeList.at(row)->preparationDuration();
            break;
        case RecipeRoles::OvenConfiguration:
        {
            auto ovenConf = _recipeList.at(row)->ovenConfiguration();
            return QVariant::fromValue(ovenConf);
            break;
        }
        default:
            return QVariant();
    }
}

QHash<int, QByteArray> RecipeListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[RecipeRoles::Title] = "title";
    roles[RecipeRoles::Content] = "content";
    roles[RecipeRoles::Difficulty] = "difficulty";
    roles[RecipeRoles::PreparationDuration] = "preparationDuration";
    roles[RecipeRoles::OvenConfiguration] = "ovenConfiguration";

    return roles;
}

void RecipeListModel::append(Recipe *recipe)
{
    if (recipe != nullptr)
    {
        const int pos = _recipeList.count();
        beginInsertRows({}, pos, pos);
        _recipeList.append(recipe);
        endInsertRows();
    }
}
