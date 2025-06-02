#include "mylayout.h"

MyLayout::MyLayout() {}


void MyLayout::Layout_45_110(QWidget *widget, QSize windowSize, QPointF widgetPoint){
    double heightFactor = windowSize.height() / 500.0;
    double widthFactor = windowSize.width() / 800.0;
    widget->move(widgetPoint.x() * widthFactor, widgetPoint.y() * heightFactor);
    widget->setMinimumHeight(45 * heightFactor);
    widget->setMinimumWidth(110 * widthFactor);
    widget->setMaximumHeight(45 * heightFactor);
    widget->setMaximumWidth(110 * widthFactor);
}

void MyLayout::Layout_450_450(QWidget *widget, QSize windowSize, QPointF widgetPoint) {
    double heightFactor = windowSize.height() / 600.0;
    double widthFactor = windowSize.width() / 800.0;
    widget->move(widgetPoint.x() * widthFactor, widgetPoint.y() * heightFactor);
    widget->setMinimumHeight(450 * heightFactor);
    widget->setMinimumWidth(450 * widthFactor);
    widget->setMaximumHeight(450 * heightFactor);
    widget->setMaximumWidth(450 * widthFactor);
}

void MyLayout::Layout_40_90(QWidget *widget, QSize windowSize, QPointF widgetPoint) {
    double heightFactor = windowSize.height() / 600.0;
    double widthFactor = windowSize.width() / 800.0;
    widget->move(widgetPoint.x() * widthFactor, widgetPoint.y() * heightFactor);
    widget->setMinimumHeight(40 * heightFactor);
    widget->setMinimumWidth(90 * widthFactor);
    widget->setMaximumHeight(40 * heightFactor);
    widget->setMaximumWidth(90 * widthFactor);
}

void MyLayout::Layout_40_220(QWidget *widget, QSize windowSize, QPointF widgetPoint)
{
    double heightFactor = windowSize.height() / 300.0;
    double widthFactor = windowSize.width() / 400.0;
    widget->move(widgetPoint.x() * widthFactor, widgetPoint.y() * heightFactor);
    widget->setMinimumHeight(40 * heightFactor);
    widget->setMinimumWidth(220 * widthFactor);
    widget->setMaximumHeight(40 * heightFactor);
    widget->setMaximumWidth(220 * widthFactor);
}

void MyLayout::Layout_40_350(QWidget *widget, QSize windowSize, QPointF widgetPoint)
{
    double heightFactor = windowSize.height() / 600.0;
    double widthFactor = windowSize.width() / 800.0;
    widget->move(widgetPoint.x() * widthFactor, widgetPoint.y() * heightFactor);
    widget->setMinimumHeight(40 * heightFactor);
    widget->setMinimumWidth(350 * widthFactor);
    widget->setMaximumHeight(40 * heightFactor);
    widget->setMaximumWidth(350 * widthFactor);
}

void MyLayout::Layout_410_250(QWidget *widget, QSize windowSize, QPointF widgetPoint) {
    double heightFactor = windowSize.height() / 600.0;
    double widthFactor = windowSize.width() / 800.0;
    widget->move(widgetPoint.x() * widthFactor, widgetPoint.y() * heightFactor);
    widget->setMinimumHeight(410 * heightFactor);
    widget->setMinimumWidth(250 * widthFactor);
    widget->setMaximumHeight(410 * heightFactor);
    widget->setMaximumWidth(250 * widthFactor);
}

void MyLayout::Layout_450_250(QWidget *widget, QSize windowSize, QPointF widgetPoint) {
    double heightFactor = windowSize.height() / 600.0;
    double widthFactor = windowSize.width() / 800.0;
    widget->move(widgetPoint.x() * widthFactor, widgetPoint.y() * heightFactor);
    widget->setMinimumHeight(450 * heightFactor);
    widget->setMinimumWidth(250 * widthFactor);
    widget->setMaximumHeight(450 * heightFactor);
    widget->setMaximumWidth(250 * widthFactor);
}

void MyLayout::Layout_30_200(QWidget *widget, QSize windowSize, QPointF widgetPoint) {
    double heightFactor = windowSize.height() / 600.0;
    double widthFactor = windowSize.width() / 800.0;
    widget->move(widgetPoint.x() * widthFactor, widgetPoint.y() * heightFactor);
    widget->setMinimumHeight(30 * heightFactor);
    widget->setMinimumWidth(200 * widthFactor);
    widget->setMaximumHeight(30 * heightFactor);
    widget->setMaximumWidth(200 * widthFactor);
}

void MyLayout::Layout_30_45(QWidget *widget, QSize windowSize, QPointF widgetPoint)
{
    double heightFactor = windowSize.height() / 600.0;
    double widthFactor = windowSize.width() / 800.0;
    widget->move(widgetPoint.x() * widthFactor, widgetPoint.y() * heightFactor);
    widget->setMinimumHeight(30 * heightFactor);
    widget->setMinimumWidth(45 * widthFactor);
    widget->setMaximumHeight(30 * heightFactor);
    widget->setMaximumWidth(45 * widthFactor);
}

