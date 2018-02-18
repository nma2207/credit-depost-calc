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
    tab->addTab(new CreditCalcWidget(), "Кредитный");
    tab->addTab(new DepositCalcWidget(), "Депозитный");
    tab->setBaseSize(500,500);
    this->setCentralWidget(tab);
}

MainWindow::~MainWindow()
{
    delete ui;
}
