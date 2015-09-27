#pragma once

#include "../Common.h"
#include "entityx\System.h"
#include "../EventLibrary.h"
#include <map>
#include <queue>

#define TEXTURE_MAP_T std::map<std::string, sf::Texture>

#define ANIMATION_MAP_T std::map<std::string, rvn::Animation>

namespace Raven {

    class RenderingSystem : public entityx::System<RenderingSystem>, 
        public ex::Receiver<RenderingSystem> {
    public:
        // Perform initializations
        explicit RenderingSystem() {

        }

        // Subscribe to events
        void configure(entityx::EventManager &event_manager) {

        }

        // Base receive
        template <typename T>
        void receiveEvent(const T &aEvent) {
            eventToggle = eventToggle ? response(aEvent) && false : true;
        }

        // Picks up CollisionEvents
        //void receive(const CollisionEvent &event);
        
        //Processes the collision of two Entities with Colliders.
        //bool response(const CollisionEvent &event);

        // Initialize loading of textures
        void initialize(entityx::EntityManager &es, sf::RenderWindow &window);

        // Add or remove textures & sprites dynamically, drawing sprites that are within view
        void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;

        // Register an Animation asset to permit access from Animators
        void registerAnimation(const std::string &animationName, Animation* const animation);

        // Register a texture asset to permit access from Animations and SpriteRenderers
        void registerTexture(std::string textureFileName);
            
        // A mapping between texture file names and texture assets
        TEXTURE_MAP_T textureMap;

        // A mapping between animation names and Animation assets
        ANIMATION_MAP_T animationMap;

        // A pointer to the window used for rendering
        sf::RenderWindow *renderWindow;

        // A Renderable min-heap for determining draw order of text, shapes, and sprites
        std::priority_queue<Renderable> renderableHeap;
    };

}