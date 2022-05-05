#include "mainwindow.h"
#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *window = new QWidget();
    window->setWindowTitle("Повзунок");

    QSpinBox *sp = new QSpinBox;
    sp->setRange(0,100);

    QSlider * slH = new QSlider(Qt::Horizontal);
    slH->setRange(0,150);
    QSlider * slV = new QSlider(Qt::Vertical);
    slV->setRange(0,150);

    QPushButton * btn = new QPushButton("Exit");
    btn->show();

    QObject::connect(btn, SIGNAL(clicked()), &a, SLOT(quit()));//для кнопки
    QObject::connect(slH, SIGNAL(valueChanged(int)), sp, SLOT(setValue(int)));
    QObject::connect(sp, SIGNAL(valueChanged(int)), slH, SLOT(setValue(int)));

    QObject::connect(slH, SIGNAL(valueChanged(int)), slV, SLOT(setValue(int)));
    QObject::connect(slV, SIGNAL(valueChanged(int)),slH, SLOT(setValue(int)));
    QObject::connect(sp, SIGNAL(valueChanged(int)),slH, SLOT(setValue(int)));

    sp->setValue(50);

    QHBoxLayout *Hbl = new QHBoxLayout;
    Hbl->addWidget(sp);
    Hbl->addWidget(slH);
    Hbl->addWidget(slV);
    Hbl->addWidget(btn);

    window->setLayout(Hbl);

    window->show();

    return a.exec();
}
