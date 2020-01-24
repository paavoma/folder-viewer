#ifndef TREEVIEWTEST_H
#define TREEVIEWTEST_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class TreeViewTest;
}

class TreeViewTest : public QDialog
{
    Q_OBJECT

public:
    explicit TreeViewTest(QWidget *parent = 0);
    ~TreeViewTest();

private slots:
    void on_treeView_doubleClicked(const QModelIndex &index);

private:
    Ui::TreeViewTest *ui;

    //Luodaan mallit kansio ja tiedostonäkymälle
    QFileSystemModel *dirModel;
    //QFileSystemModel *fileModel;
};

#endif // TREEVIEWTEST_H

