#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include "creditcalcwidget.h"
#include "depositcalcwidget.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTabWidget *tab=new QTabWidget();
    CreditCalcWidget *creditCalcWidget=new CreditCalcWidget();
    tab->addTab(creditCalcWidget, "Кредитный");
    tab->addTab(new DepositCalcWidget(), "Депозитный");

    //tab->setBaseSize(500,500);
    this->setMinimumWidth(creditCalcWidget->getWidth()+200);
    this->setCentralWidget(tab);
}

MainWindow::~MainWindow()
{
    delete ui;
}
