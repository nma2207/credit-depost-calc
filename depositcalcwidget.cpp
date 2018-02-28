#include "depositcalcwidget.h"
#include <QVBoxLayout>
#include<QGridLayout>
#include<QHeaderView>
#include<QLocale>
#include"myqtablewidgetite.h"
DepositCalcWidget::DepositCalcWidget(QWidget *parent) : QWidget(parent)
{
    sumLabel = new QLabel ("Сумма (руб.)");
    procentLabel = new QLabel ("Процент годовых");
    timeLabel = new QLabel("Период (мес.)");
    startDepLabel = new QLabel("Начало выплат");

    sumLine = new QLineEdit();
    procentLine = new QLineEdit();
    timeLine = new QLineEdit();
    startDepositDate = new QDateEdit(QDate::currentDate());
    startDepositDate->setDisplayFormat("MMMM yyyy");

    QGridLayout* layout =  new QGridLayout;
    layout->addWidget(sumLabel,0,0);
    layout->addWidget(procentLabel,1,0);
    layout->addWidget(timeLabel,2,0);
    layout->addWidget(startDepLabel, 3, 0);

    layout->addWidget(sumLine,0,1);
    layout->addWidget(procentLine,1,1);
    layout->addWidget(timeLine,2,1);
    layout->addWidget(startDepositDate, 3, 1);


    QVBoxLayout *genLayout=new QVBoxLayout;
    genLayout->addLayout(layout);

    depositTable = new QTableWidget;
    depositTable->setColumnCount(4);

    depositTable->setHorizontalHeaderLabels({"№ выплаты","Месяц", "Cумма", "Процент"});
    depositTable->verticalHeader()->hide();

    genLayout->addWidget(depositTable);
    calcButton=new QPushButton("Рассчитать");
    connect(calcButton, SIGNAL(clicked(bool)), this, SLOT(calcDeposit()));
    genLayout->addWidget(calcButton);
    this->setLayout(genLayout);
}

void DepositCalcWidget::calcDeposit()
{
    sum = sumLine->text().toDouble();
    qreal newSum=sum;
    procent = procentLine->text().toDouble()/100. /12;
    time = timeLine->text().toInt();
    qreal sumProcent=0;
    depositTable->setRowCount(time+1);
    QLocale *c=new QLocale();
    QDate payDay = startDepositDate->date();
    for(qint32 i=0;i<time;i++)
    {
        depositTable->setItem(i, 0, new QTableWidgetItem(QString::number(i+1)));
        qreal procentPay = newSum*procent;
        newSum+=procentPay;
        sumProcent+=procentPay;
        depositTable->setItem(i, 1, new QTableWidgetItem(c->toString(payDay, "MMMM yyyy")));
        payDay = payDay.addMonths(1);
        depositTable->setItem(i,2, new MyQTableWidgetItem(c->toCurrencyString(newSum, " ")));
        depositTable->setItem(i,3, new MyQTableWidgetItem(c->toCurrencyString(procentPay, " ")));
    }
    depositTable->setItem(time, 0, new QTableWidgetItem("Итого"));
    depositTable->setItem(time,2, new MyQTableWidgetItem(c->toCurrencyString(newSum, " ")));
    depositTable->setItem(time,3, new MyQTableWidgetItem(c->toCurrencyString(sumProcent, " ")));

}
