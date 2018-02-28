#include "myqtablewidgetite.h"

MyQTableWidgetItem::MyQTableWidgetItem(const QString& str)
    :QTableWidgetItem(str)
{
    QTableWidgetItem::setTextAlignment(Qt::AlignRight);
}
