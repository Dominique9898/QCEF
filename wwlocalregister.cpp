#include "wwlocalregister.h"
#include "./ui_wwlocalregister.h"

WWLOCALREGISTER::WWLOCALREGISTER(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WWLOCALREGISTER)
{
    ui->setupUi(this);
}

WWLOCALREGISTER::~WWLOCALREGISTER()
{
    delete ui;
}


void WWLOCALREGISTER::on_pushButton_clicked()
{
    // todo
}

