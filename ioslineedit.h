#ifndef IOSLINEEDIT_H
#define IOSLINEEDIT_H

#include <QObject>
#include <QLineEdit>
#include <QApplication>

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit LineEdit(QWidget *parent = nullptr) : QLineEdit(parent)
    {
        setMaximumSize(QSize(10,10));
        move(-10,-10);
        lower();
        hide();
        connect(this, &QLineEdit::editingFinished, this, &LineEdit::hide);
    }

public slots:
    void init(const QString &currentText){
        setText(currentText);
        show();
        setFocus();
    }
};

class IosLineEdit : public QObject
{
    Q_OBJECT

public:
    explicit IosLineEdit(QObject *parent = nullptr) : QObject(parent)
    {
        QWidget *parentWidget = nullptr;
        for(auto widget : qApp->allWidgets()){
            if(widget->objectName() == "myQuickWidget")
                parentWidget = widget;
        }

        //The parent must not be nullptr, or the lineedit will take up the whole screen on iOS
        m_lineEdit =  new LineEdit(parentWidget);
        connect(m_lineEdit, &LineEdit::textChanged, this, &IosLineEdit::textChanged);
        connect(m_lineEdit, &LineEdit::editingFinished, this, &IosLineEdit::editingFinished);

        connect(this, &IosLineEdit::init, m_lineEdit, &LineEdit::init);
    }

    ~IosLineEdit()
    {
        if(m_lineEdit){
            m_lineEdit->deleteLater();
            m_lineEdit = nullptr;
        }
    }

signals:
    void textChanged(const QString &text);
    void editingFinished();

    void init(const QString &currentText);

protected:
    LineEdit *m_lineEdit = nullptr;
};

#endif // IOSLINEEDIT_H
