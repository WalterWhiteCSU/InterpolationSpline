/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                pantingwidget.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/4
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#ifndef INTERPOLATIONSPLINE_PANTINGWIDGET_H
#define INTERPOLATIONSPLINE_PANTINGWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class PantingWidget; }
QT_END_NAMESPACE

class PantingWidget : public QWidget {
Q_OBJECT

public:
    explicit PantingWidget(QWidget *parent = nullptr);

    ~PantingWidget() override;

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::PantingWidget *ui;
};


#endif //INTERPOLATIONSPLINE_PANTINGWIDGET_H
