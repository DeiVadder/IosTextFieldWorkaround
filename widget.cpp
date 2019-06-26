#include "widget.h"

#include <QtQuickWidgets>
#include <QHBoxLayout>

#include "ioslineedit.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    qmlRegisterType<IosLineEdit>("QLineEdit",1,0, "QLineEdit");

    QQuickWidget *quick = new QQuickWidget(this);
    quick->setObjectName("myQuickWidget");
    quick->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    quick->setResizeMode(QQuickWidget::SizeRootObjectToView);
    layout->addWidget(quick);
}

Widget::~Widget()
{

}
