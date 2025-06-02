#ifndef MYLAYOUT_H
#define MYLAYOUT_H
#include <QWidget>
#include <QSize>

class MyLayout
{
public:
    MyLayout();
    void static Layout_45_110(QWidget *wighet, QSize windowSize, QPointF widgetPoint);
    void static Layout_450_450(QWidget *widget, QSize windowSize, QPointF widgetPoint);
    void static Layout_40_90(QWidget *widget, QSize windowSize, QPointF widgetPoint);
    void static Layout_40_220(QWidget *widget, QSize windowSize, QPointF widgetPoint);
    void static Layout_40_350(QWidget *widget, QSize windowSize, QPointF widgetPoint);
    void static Layout_410_250(QWidget *widget, QSize windowSize, QPointF widgetPoint);
    void static Layout_450_250(QWidget *widget, QSize windowSize, QPointF widgetPoint);
    void static Layout_30_200(QWidget *widget, QSize windowSize, QPointF widgetPoint);
    void static Layout_30_45(QWidget *widget, QSize windowSize, QPointF widgetPoint);


};

#endif // MYLAYOUT_H
