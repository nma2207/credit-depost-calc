#ifndef CREDITCALCWIDGET_H
#define CREDITCALCWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
class CreditCalcWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CreditCalcWidget(QWidget *parent = 0);
private:
    QLabel *sumLabel;
    QLabel *procentLabel;
    QLabel *timeLabel;
    QLabel *typeLabel;

    QLineEdit *sumLine;
    QLineEdit *procentLine;
    QLineEdit *timeLine;
    QComboBox *typeComboBox;

    QPushButton *calcButton;
    QTableWidget *creditTable;

    qreal sum;
    qreal procent;
    qint32 time;

    void calcDiffCredit();
    void calcAnniutCredit();

signals:

public slots:
    void calcCredit();
};

#endif // CREDITCALCWIDGET_H
