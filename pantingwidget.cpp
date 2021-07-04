/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                pantingwidget.cpp
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/4
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

// You may need to build the project (run Qt uic code generator) to get "ui_PantingWidget.h" resolved

#include "pantingwidget.h"
#include "ui_PantingWidget.h"


PantingWidget::PantingWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::PantingWidget) {
    ui->setupUi(this);
}

PantingWidget::~PantingWidget() {
    delete ui;
}

