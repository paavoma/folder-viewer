#include <QtWidgets>
class FolderReader {
public:
    qint64 dirSize(QString dirPath) {
        qint64 size = 0;
        QDir dir(dirPath);
        //valitun kansion tiedostojen kokojen summa
        QDir::Filters fileFilters = QDir::Files|QDir::System|QDir::Hidden;
        for(QString filePath : dir.entryList(fileFilters)) {
            QFileInfo fi(dir, filePath);
            size+= fi.size();
        }
        //rekursiivisesti käydään alakansiot ja lisätään kokonaissummaan
        //tässä voi kestää tovin ja QDir ei ole rinnakkaisessa threadissa kiinni,
        //joten softa jökkää sen aikaa kun kansiot käydään läpi.
        QDir::Filters dirFilters = QDir::Dirs|QDir::NoDotAndDotDot|QDir::System|QDir::Hidden;
        for(QString childPath : dir.entryList(dirFilters))
            size+= dirSize(dirPath + QDir::separator() + childPath);
        return size;
    }

    QString formatSize(qint64 size) {
        //muuttaa bitit oikeiksi yksiköiksi
        QStringList units = {"Bytes", "KB", "MB", "GB", "TB"};
        int i;
        double outSize = size;
        for(i=0; i<units.size()-1; i++) {
            if(outSize<1024) break;
            outSize= outSize/1024;
        }
        return QString("%0 %1").arg(outSize, 0, 'f', 2).arg(units[i]);
    }

};
