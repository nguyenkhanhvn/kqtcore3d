#ifndef BASESHADERPROGRAM_H
#define BASESHADERPROGRAM_H


#include "shaderprogramlayout.h"

#include <QMatrix4x4>

namespace kqtcore3d
{

class BaseShaderProgram
{
public:
    BaseShaderProgram(const ShaderProgramLayout& layout);

    virtual bool init() = 0;
    virtual bool bind() = 0;
    virtual void release() = 0;

    virtual void setAttributeBuffer(int location, GLenum type, int offset, int tupleSize, int stride = 0) {}
    virtual void setAttributeBuffer(const char *name, GLenum type, int offset, int tupleSize, int stride = 0) {}
    virtual void setAttributeBuffer(int layoutId) = 0;
    virtual void setAllAttributeBuffer() = 0;

    virtual void setUniformValue(int location, GLfloat value) {}
    virtual void setUniformValue(int location, GLint value) {}
    virtual void setUniformValue(int location, GLuint value) {}
    virtual void setUniformValue(int location, GLfloat x, GLfloat y) {}
    virtual void setUniformValue(int location, GLfloat x, GLfloat y, GLfloat z) {}
    virtual void setUniformValue(int location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {}
    virtual void setUniformValue(int location, const QVector2D& value) {}
    virtual void setUniformValue(int location, const QVector3D& value) {}
    virtual void setUniformValue(int location, const QVector4D& value) {}
    virtual void setUniformValue(int location, const QColor& color) {}
    virtual void setUniformValue(int location, const QPoint& point) {}
    virtual void setUniformValue(int location, const QPointF& point) {}
    virtual void setUniformValue(int location, const QSize& size) {}
    virtual void setUniformValue(int location, const QSizeF& size) {}
    virtual void setUniformValue(int location, const QMatrix2x2& value) {}
    virtual void setUniformValue(int location, const QMatrix2x3& value) {}
    virtual void setUniformValue(int location, const QMatrix2x4& value) {}
    virtual void setUniformValue(int location, const QMatrix3x2& value) {}
    virtual void setUniformValue(int location, const QMatrix3x3& value) {}
    virtual void setUniformValue(int location, const QMatrix3x4& value) {}
    virtual void setUniformValue(int location, const QMatrix4x2& value) {}
    virtual void setUniformValue(int location, const QMatrix4x3& value) {}
    virtual void setUniformValue(int location, const QMatrix4x4& value) {}
    virtual void setUniformValue(int location, const GLfloat value[2][2]) {}
    virtual void setUniformValue(int location, const GLfloat value[3][3]) {}
    virtual void setUniformValue(int location, const GLfloat value[4][4]) {}
    virtual void setUniformValue(int location, const QTransform& value) {}

    virtual void setUniformValue(const char *name, GLfloat value) {}
    virtual void setUniformValue(const char *name, GLint value) {}
    virtual void setUniformValue(const char *name, GLuint value) {}
    virtual void setUniformValue(const char *name, GLfloat x, GLfloat y) {}
    virtual void setUniformValue(const char *name, GLfloat x, GLfloat y, GLfloat z) {}
    virtual void setUniformValue(const char *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {}
    virtual void setUniformValue(const char *name, const QVector2D& value) {}
    virtual void setUniformValue(const char *name, const QVector3D& value) {}
    virtual void setUniformValue(const char *name, const QVector4D& value) {}
    virtual void setUniformValue(const char *name, const QColor& color) {}
    virtual void setUniformValue(const char *name, const QPoint& point) {}
    virtual void setUniformValue(const char *name, const QPointF& point) {}
    virtual void setUniformValue(const char *name, const QSize& size) {}
    virtual void setUniformValue(const char *name, const QSizeF& size) {}
    virtual void setUniformValue(const char *name, const QMatrix2x2& value) {}
    virtual void setUniformValue(const char *name, const QMatrix2x3& value) {}
    virtual void setUniformValue(const char *name, const QMatrix2x4& value) {}
    virtual void setUniformValue(const char *name, const QMatrix3x2& value) {}
    virtual void setUniformValue(const char *name, const QMatrix3x3& value) {}
    virtual void setUniformValue(const char *name, const QMatrix3x4& value) {}
    virtual void setUniformValue(const char *name, const QMatrix4x2& value) {}
    virtual void setUniformValue(const char *name, const QMatrix4x3& value) {}
    virtual void setUniformValue(const char *name, const QMatrix4x4& value) {}
    virtual void setUniformValue(const char *name, const GLfloat value[2][2]) {}
    virtual void setUniformValue(const char *name, const GLfloat value[3][3]) {}
    virtual void setUniformValue(const char *name, const GLfloat value[4][4]) {}
    virtual void setUniformValue(const char *name, const QTransform& value) {}

    virtual ShaderProgramLayout getLayout() const;
    virtual void setLayouts(const ShaderProgramLayout& layout);

protected:
    ShaderProgramLayout m_layout;

};

}

#endif // BASESHADERPROGRAM_H
