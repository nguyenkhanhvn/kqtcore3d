#ifndef IMODELIMPORTER_H
#define IMODELIMPORTER_H


#include "mesh.h"

namespace kqtcore3d
{

struct ModelImporterData
{
    bool isLoaded = false;
    QVector<QSharedPointer<Mesh>> meshes;
};

class IModelImporter
{
public:
    virtual ModelImporterData loadModel(const QString &filename) = 0;
    virtual ModelImporterData loadModelFromMemory(const QByteArray &data) = 0;
};

}

#endif // IMODELIMPORTER_H
