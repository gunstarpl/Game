#pragma once

#include "Precompiled.hpp"
#include "EntitySubsystem.hpp"
#include "Graphics/ShapeRenderer.hpp"

// Forward declarations.
class Entity;

//
// Render System
//

class RenderSystem : public EntitySubsystem
{
public:
    RenderSystem();
    ~RenderSystem();

    bool Initialize();
    void Cleanup();

    void Draw();

private:
    // Prepares processing.
    void PrepareProcessing();

    // Processes an entity.
    void Process(Entity* entity);

    // Finishes processing.
    void FinishProcessing();

private:
    // Render shapes.
    std::vector<ShapeRenderer::Quad> m_shapes;

    // Render state.
    glm::mat4 m_projection;
};
