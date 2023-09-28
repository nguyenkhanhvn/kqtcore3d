#ifndef IMODELIMPORTER_H
#define IMODELIMPORTER_H


#include "kqtcore3d/core/basemesh.h"

namespace kqtcore3d
{

template<typename I>
struct ModelImporterData
{
    bool isLoaded = false;
    QVector<QSharedPointer<BaseMesh<I>>> meshes;
};

template<typename I>
class IModelImporter
{
public:
    virtual ModelImporterData<I> loadModel(const QString &filename) = 0;
    virtual ModelImporterData<I> loadModelFromMemory(const QByteArray &data) = 0;
};

}

#endif // IMODELIMPORTER_H
