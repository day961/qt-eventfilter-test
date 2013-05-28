#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->installEventFilter(this);//为lineEdit安装事件过滤器
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *O, QEvent *E)
{
    if(O == ui->lineEdit)
    {
        if(E->type() == QKeyEvent::KeyPress)
        {
            QKeyEvent *pkey = (QKeyEvent *)E;
            if(!((pkey->key()>=Qt::Key_0&&pkey->key()<=Qt::Key_9)//判断是否是1~9
                 ||pkey->key()==Qt::Key_Backspace//判断是否是退格键
                 ||pkey->key()==Qt::Key_Left//是否键盘左
                 ||pkey->key()==Qt::Key_Right))//是否键盘右
                    return true;
        }
    }
    return QWidget::eventFilter(O,E);
}
