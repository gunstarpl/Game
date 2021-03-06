#pragma once

#include "Precompiled.hpp"

//
// Buffer
//  Base class implementation for vertex, index and instance buffers.
//

class Buffer
{
protected:
    Buffer(GLenum type);
    virtual ~Buffer();

public:
    // Initializes the buffer.
    bool Initialize(unsigned int elementSize, unsigned int elementCount, const void* data, GLenum usage = GL_STATIC_DRAW);

    // Restores class instance to it's original state.
    void Cleanup();

    // Update buffer data.
    void Update(const void* data, int count = -1);

    // Checks if the buffer is valid.
    bool IsValid() const;

    // Gets the buffer type.
    GLenum GetType() const
    {
        return m_type;
    }

    // Gets the buffer handle.
    GLuint GetHandle() const
    {
        return m_handle;
    }

    // Gets the buffer element size.
    unsigned int GetElementSize() const
    {
        return m_elementSize;
    }

    // Gets the buffer element count.
    unsigned int GetElementCount() const
    {
        return m_elementCount;
    }

    // Gets the buffer element type.
    virtual GLenum GetElementType() const
    {
        return GL_INVALID_ENUM;
    }

    // Check if buffer is instanced.
    virtual bool IsInstanced() const
    {
        return false;
    }

protected:
    GLenum m_type;
    GLuint m_handle;

    unsigned int m_elementSize;
    unsigned int m_elementCount;
};

//
// Vertex Buffer
//

class VertexBuffer : public Buffer
{
public:
    VertexBuffer() :
        Buffer(GL_ARRAY_BUFFER)
    {
    }
};

//
// Index Buffer
//

class IndexBuffer : public Buffer
{
public:
    IndexBuffer() :
        Buffer(GL_ELEMENT_ARRAY_BUFFER)
    {
    }

    GLenum GetElementType() const;
};

//
// Instance Buffer
//

class InstanceBuffer : public Buffer
{
public:
    InstanceBuffer() :
        Buffer(GL_ARRAY_BUFFER)
    {
    }

    bool IsInstanced() const
    {
        return true;
    }
};
