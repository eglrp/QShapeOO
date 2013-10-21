#ifndef QSHAPE_H
#define QSHAPE_H

#include "../Bridge/qdrawinterface.h"

#include <QTime>
#include <QPoint>
#include <QPen>
#include <QBrush>

enum EShapeType
{
    eTriangle,
    eRect,
    eCircle
};


/**
* ��Ҫ�Ľ��ĵط��ǣ���Shape���漰�����ݷ�װ��Ϊһ����ShapeData���������ܹ�ʵ�ֲ�ͬ��Shapeȥ
* ������ͬ�����ݻ���ShapeData
**/
class QShape
{
public:
    QShape(QString name);
    virtual ~QShape();

    virtual void draw(QPainter* painter);

    virtual float getArea();

    virtual void setSelected(bool isSelected);
    virtual void move(int x, int y);
    virtual void zoomIn();
    virtual void zoomOut();
    virtual void setLineColor(QColor color);
    virtual void setLineType(Qt::PenStyle penStyle);
    virtual void save(QDataStream& out);

    virtual bool isSelected(QPoint point);
    virtual void setData(QPoint p[]);
    virtual void setData(float topleftX, float topleftY, float width, float height);
    virtual void setData(int radius, int px, int py);

    void setName(QString name);
    QString getName();
    void setDrawer(QDrawInterface* drawer);
    QDrawInterface* getDrawer();

    void setType(EShapeType shapeType);
    int getType();

    float getSizeRate();

protected:
    QString             m_name;
    QDrawInterface*     m_drawerInterface;

    float               m_sizeRate;
    EShapeType          m_shapeType;
};

#endif // QSHAPE_H
