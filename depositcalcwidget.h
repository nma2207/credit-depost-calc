#ifndef DEPOSITCALCWIDGET_H
#define DEPOSITCALCWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
class DepositCalcWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DepositCalcWidget(QWidget *parent = 0);

private:
    QLabel *sumLabel;
    QLabel *procentLabel;
    QLabel *timeLabel;


    QLineEdit *sumLine;
    QLineEdit *procentLine;
    QLineEdit *timeLine;


    QPushButton *calcButton;
    QTableWidget *depositTable;

    qreal sum;
    qreal procent;
    qint32 time;

signals:

public slots:
    void calcDeposit();
};

#endif // DEPOSITCALCWIDGET_H
