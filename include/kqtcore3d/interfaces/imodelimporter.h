#ifndef IMODELIMPORTER_H
#define IMODELIMPORTER_H


#include "kqtcore3d/core/basemesh.h"

namespace kqtcore3d
{

template<typename IndexType>
struct ModelImporterData
{
    bool isLoaded = false;
    QVector<QSharedPointer<BaseMesh<IndexType>>> meshes;
};

template<typename IndexType>
class IModelImporter
{
public:
    virtual ModelImporterData<IndexType> loadModel(const QString &filename, QMatrix4x4 matrix = QMatrix4x4()) = 0;
    virtual ModelImporterData<IndexType> loadModelFromMemory(const QByteArray &data, QMatrix4x4 matrix = QMatrix4x4()) = 0;
};

}

#endif // IMODELIMPORTER_H
