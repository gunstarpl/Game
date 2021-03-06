#pragma once

#include "Precompiled.hpp"
#include "Game/Entity/EntityHandle.hpp"

// Forward declarations.
class Services;
class EventSystem;
class EntitySystem;
class IdentitySystem;
class ComponentSystem;

//
// Health System
//

class HealthSystem
{
public:
    HealthSystem();
    ~HealthSystem();

    bool Initialize(const Services& services);
    void Cleanup();

    void Damage(EntityHandle entity, int value);
    void Heal(EntityHandle entity, int value);

private:
    // System state.
    bool m_initialized;

    // Game systems.
    EventSystem*     m_eventSystem;
    EntitySystem*    m_entitySystem;
    IdentitySystem*  m_identitySystem;
    ComponentSystem* m_componentSystem;
};
