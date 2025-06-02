#ifndef WORKWITHPIXMAP_H
#define WORKWITHPIXMAP_H

#include <QPixmap>
#include <QGraphicsScene>

class WorkWithPixmap
{
public:
    WorkWithPixmap();

    QPixmap static TranslationInPixmap(QGraphicsScene *scene);

};

#endif // WORKWITHPIXMAP_H
