#pragma once

#include "Precompiled.hpp"
#include "CollisionObject.hpp"

#include "Common/Dispatcher.hpp"
#include "Game/GameEvents.hpp"
#include "Game/Entity/EntityHandle.hpp"

//
// Collision System
//

class CollisionSystem
{
public:
    static const float Permanent;

public:
    CollisionSystem();
    ~CollisionSystem();

    bool Initialize();
    void Cleanup();

    void Update(float timeDelta);

    void DisableCollisionResponse(EntityHandle sourceEntity, EntityHandle targetEntity, float duration = Permanent);

public:
    void SubscribeReceiver(const ReceiverSignature<GameEvent::EntityCollision>& signature);

private:
    // Intermediate collision objects.
    std::vector<CollisionObject> m_objects;

    // Disabled collision responses.
    typedef std::pair<EntityHandle, EntityHandle> EntityPair;
    typedef std::unordered_multimap<EntityPair, float> DisabledList;

    DisabledList m_disabled;

    // Event dispatchers.
    Dispatcher<GameEvent::EntityCollision> m_dispatcherEntityCollision;
};
