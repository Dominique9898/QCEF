#ifndef WWLOCALREGISTER_H
#define WWLOCALREGISTER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WWLOCALREGISTER; }
QT_END_NAMESPACE

class WWLOCALREGISTER : public QMainWindow
{
    Q_OBJECT

public:
    WWLOCALREGISTER(QWidget *parent = nullptr);
    ~WWLOCALREGISTER();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WWLOCALREGISTER *ui;
};
#endif // WWLOCALREGISTER_H
