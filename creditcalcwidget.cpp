#include "creditcalcwidget.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include<QLocale>
CreditCalcWidget::CreditCalcWidget(QWidget *parent) : QWidget(parent)
{
    sumLabel = new QLabel ("Сумма (руб.)");
    procentLabel = new QLabel ("Процент годовых");
    timeLabel = new QLabel("Период (мес.)");
    typeLabel = new QLabel ("Схема кредитования");

    sumLine = new QLineEdit();
    procentLine = new QLineEdit();
    timeLine = new QLineEdit();
    typeComboBox = new QComboBox();
    typeComboBox->addItems({"Дифференцированный", "Аннуитетный"});

    QGridLayout* layout =  new QGridLayout;
    layout->addWidget(sumLabel,0,0);
    layout->addWidget(procentLabel,1,0);
    layout->addWidget(timeLabel,2,0);
    layout->addWidget(typeLabel,3,0);
    layout->addWidget(sumLine,0,1);
    layout->addWidget(procentLine,1,1);
    layout->addWidget(timeLine,2,1);
    layout->addWidget(typeComboBox,3,1);

    QVBoxLayout *genLayout=new QVBoxLayout;
    genLayout->addLayout(layout);

    creditTable = new QTableWidget;
    creditTable->setColumnCount(5);

    creditTable->setHorizontalHeaderLabels({"№ месяца", "Остаток","Основной", "Процент", "Общий платеж"});
    creditTable->verticalHeader()->hide();

    genLayout->addWidget(creditTable);
    calcButton=new QPushButton("Рассчитать");
    connect(calcButton, SIGNAL(clicked(bool)), this, SLOT(calcCredit()));
    genLayout->addWidget(calcButton);
    this->setLayout(genLayout);

}
void CreditCalcWidget::calcCredit()
{
    sum = sumLine->text().toDouble();
    procent = procentLine->text().toDouble()/100. /12;
    time = timeLine->text().toInt();

    QString type = typeComboBox->currentText();
    creditTable->setRowCount(time+1);
    //creditTable->clear();
    //creditTable->setHorizontalHeaderLabels({"№ месяца", "Остаток","Основной", "Процент", "Общий платеж"});

    if(type=="Дифференцированный")
        this->calcDiffCredit();
    if(type=="Аннуитетный")
        this->calcAnniutCredit();
}
void CreditCalcWidget::calcDiffCredit()
{
    qreal remain = sum;
    qreal basePay = sum/time;
    qreal result=0;
    qreal sumProcent=0;

    for(int i=0;i<time; i++)
    {
        creditTable->setItem(i,0, new QTableWidgetItem(QString::number(i+1)));
        creditTable->setItem(i,1, new QTableWidgetItem(QString::number(remain,'f',2)));
        creditTable->setItem(i,2, new QTableWidgetItem(QString::number(basePay,'f',2)));
        qreal percentPay = remain*procent;
        creditTable->setItem(i,3, new QTableWidgetItem(QString::number(percentPay,'f',2)));
        creditTable->setItem(i,4, new QTableWidgetItem(QString::number(basePay+percentPay,'f',2)));
        remain-=basePay;
        result+=(basePay+percentPay);
        sumProcent+=percentPay;

    }
    creditTable->setItem(time,0, new QTableWidgetItem("Итого"));
    creditTable->setItem(time,1, new QTableWidgetItem(QString::number(0, 'f',2)));
    creditTable->setItem(time,2, new QTableWidgetItem(QString::number(sum, 'f',2)));

    creditTable->setItem(time,3, new QTableWidgetItem(QString::number(sumProcent, 'f',2)));
    creditTable->setItem(time,4, new QTableWidgetItem(QString::number(result, 'f',2)));
}
qreal powN(qreal a, qint32 n)
{
    qreal res= 1;
    for(qint32 i =0;i<n;i++)
        res*=a;
    return res;
}

void CreditCalcWidget::calcAnniutCredit()
{
    qreal monthPay= sum*(procent+(procent/(powN(1+procent, time)-1)));
    qreal remain=sum;
    qreal result=0;
    qreal resultPercent=0;
    for(int i=0;i<time; i++)
    {
        creditTable->setItem(i,0, new QTableWidgetItem(QString::number(i+1)));
        creditTable->setItem(i,1, new QTableWidgetItem(QString::number(remain,'f',2)));
        qreal percentPay = remain*procent;
        qreal basePay = monthPay-percentPay;
        creditTable->setItem(i,2, new QTableWidgetItem(QString::number(basePay,'f',2)));
        creditTable->setItem(i,3, new QTableWidgetItem(QString::number(percentPay,'f',2)));
        creditTable->setItem(i,4, new QTableWidgetItem(QString::number(monthPay,'f',2)));
        result +=monthPay;
        resultPercent+=percentPay;
        remain-=basePay;

    }

    creditTable->setItem(time,0, new QTableWidgetItem("Итого"));
    creditTable->setItem(time,1, new QTableWidgetItem(QString::number(0,'f',2)));
    creditTable->setItem(time,2, new QTableWidgetItem(QString::number(sum,'f',2)));

    creditTable->setItem(time,3, new QTableWidgetItem(QString::number(resultPercent,'f',2)));
    creditTable->setItem(time,4, new QTableWidgetItem(QString::number(result,'f',2)));

}
