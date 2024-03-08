#include "Chef.h"

#include <QDebug>

Chef::Chef(QObject *parent) : QObject{parent} {}

Chef::~Chef() { qDebug() << "Chef is deleted !!"; }
