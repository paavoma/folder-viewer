#include "treeviewtest.h"
#include "ui_treeviewtest.h"
#include "folderreader.cpp"
#include <QDebug>

TreeViewTest::TreeViewTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TreeViewTest)
{
    ui->setupUi(this);
    QString mPath = "C:/";
    dirModel = new QFileSystemModel(this);

    // asetetaan filtterit näyttämään vain kansiot
    dirModel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    // modeli tarvii pathin josta alottaa
    dirModel->setRootPath(mPath);
    // kinnittää viewiin modelin
    ui->treeView->setModel(dirModel);
    //piilotetaan muut kolumnit paitsi nimi
    int i;
    for(i=1; i<=3; i++){
     ui->treeView->setColumnHidden(i, true);
    }

}

TreeViewTest::~TreeViewTest()
{
    delete ui;
}


void TreeViewTest::on_treeView_doubleClicked(const QModelIndex &index)
{

    FolderReader* reader = new FolderReader;

    // ottaa absolute filepathin missä valinta on
    QString dirPath = dirModel->fileInfo(index).absoluteFilePath();
    qint64 size = reader->dirSize(dirPath);
    ui->labelSizeValue -> setText(reader->formatSize(size));
    qInfo() << reader->formatSize(size);

    delete reader;

}
