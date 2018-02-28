#ifndef MYQTABLEWIDGETITE_H
#define MYQTABLEWIDGETITE_H
#include<QTableWidgetItem>

class MyQTableWidgetItem : public QTableWidgetItem
{
public:
    MyQTableWidgetItem(const QString& str);
};

#endif // MYQTABLEWIDGETITE_H
