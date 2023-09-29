#ifndef OPENGLSHADERPROGRAM_H
#define OPENGLSHADERPROGRAM_H


#include <QOpenGLShaderProgram>

#include "shaderprogram.h"

namespace kqtcore3d {

class OpenGLShaderProgram : public ShaderProgram
{
public:
    OpenGLShaderProgram(const QString& vertexShaderSource, const QString& fragmentShaderSource, const QVector<ShaderLayout>& layout);

    // BaseShaderProgram interface
    virtual bool init() override;
    virtual bool bind() override;
    virtual void release() override;
    virtual void setAttributeBuffer(int layoutId, int stride) override;
    virtual void setAllAttributeBuffer(int stride) override;

    // IRenderCallbacks interface
    virtual void initAttribBufferCallBack(int stride) override;


    virtual void setUniformValue(int location, GLfloat value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, GLint value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, GLuint value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, GLfloat x, GLfloat y) override {m_program.setUniformValue(location, x, y);}
    virtual void setUniformValue(int location, GLfloat x, GLfloat y, GLfloat z) override {m_program.setUniformValue(location, x, y, z);}
    virtual void setUniformValue(int location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) override {m_program.setUniformValue(location, x, y, z, w);}
    virtual void setUniformValue(int location, const QVector2D& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QVector3D& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QVector4D& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QColor& color) override {m_program.setUniformValue(location, color);}
    virtual void setUniformValue(int location, const QPoint& point) override {m_program.setUniformValue(location, point);}
    virtual void setUniformValue(int location, const QPointF& point) override {m_program.setUniformValue(location, point);}
    virtual void setUniformValue(int location, const QSize& size) override {m_program.setUniformValue(location, size);}
    virtual void setUniformValue(int location, const QSizeF& size) override {m_program.setUniformValue(location, size);}
    virtual void setUniformValue(int location, const QMatrix2x2& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QMatrix2x3& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QMatrix2x4& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QMatrix3x2& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QMatrix3x3& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QMatrix3x4& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QMatrix4x2& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QMatrix4x3& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QMatrix4x4& value) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const GLfloat value[2][2]) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const GLfloat value[3][3]) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const GLfloat value[4][4]) override {m_program.setUniformValue(location, value);}
    virtual void setUniformValue(int location, const QTransform& value) override {m_program.setUniformValue(location, value);}

    virtual void setUniformValue(const char *name, GLfloat value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, GLint value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, GLuint value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, GLfloat x, GLfloat y) override {m_program.setUniformValue(name, x, y);}
    virtual void setUniformValue(const char *name, GLfloat x, GLfloat y, GLfloat z) override {m_program.setUniformValue(name, x, y, z);}
    virtual void setUniformValue(const char *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) override {m_program.setUniformValue(name, x, y, z, w);}
    virtual void setUniformValue(const char *name, const QVector2D& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QVector3D& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QVector4D& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QColor& color) override {m_program.setUniformValue(name, color);}
    virtual void setUniformValue(const char *name, const QPoint& point) override {m_program.setUniformValue(name, point);}
    virtual void setUniformValue(const char *name, const QPointF& point) override {m_program.setUniformValue(name, point);}
    virtual void setUniformValue(const char *name, const QSize& size) override {m_program.setUniformValue(name, size);}
    virtual void setUniformValue(const char *name, const QSizeF& size) override {m_program.setUniformValue(name, size);}
    virtual void setUniformValue(const char *name, const QMatrix2x2& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QMatrix2x3& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QMatrix2x4& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QMatrix3x2& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QMatrix3x3& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QMatrix3x4& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QMatrix4x2& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QMatrix4x3& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QMatrix4x4& value) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const GLfloat value[2][2]) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const GLfloat value[3][3]) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const GLfloat value[4][4]) override {m_program.setUniformValue(name, value);}
    virtual void setUniformValue(const char *name, const QTransform& value) override {m_program.setUniformValue(name, value);}


private:
    QOpenGLShaderProgram m_program;

};

}

#endif // OPENGLSHADERPROGRAM_H
