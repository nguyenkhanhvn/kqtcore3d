#ifndef IMODELIMPORTER_H
#define IMODELIMPORTER_H


#include "kqtcore3d/core/basemesh.h"

namespace kqtcore3d
{

struct ModelImporterData
{
    bool isLoaded = false;
    QVector<QSharedPointer<BaseMesh>> meshes;
};

class IModelImporter
{
public:
    virtual ModelImporterData loadModel(const QString &filename, QMatrix4x4 matrix = QMatrix4x4()) = 0;
    virtual ModelImporterData loadModelFromMemory(const QByteArray &data, QMatrix4x4 matrix = QMatrix4x4()) = 0;
};

}

#endif // IMODELIMPORTER_H
