#pragma once
#include "entityx/entityx.h"
#include "Common.h"
#include "SFML/Graphics.hpp"

namespace Raven {

    class Game : public ex::EntityX {
    public:
        explicit Game(sf::RenderTarget &target);
        explicit Game();

        void update(ex::TimeDelta dt);

        // Provides custom method for assigning default components to an entity
        ex::Entity makeEntity();
        // Creates a default entity and assigns it the given name
        ex::Entity makeEntity(std::string name);
        // Creates an instance of the prefab and assigns it the given name
        std::shared_ptr<ex::Entity> instantiatePrefab(std::string name, std::string prefabName);

        // The name of the level to which newly made entities are currently assigned
        std::string currentLevelName;

        // Used to create unique entity names and track the number of entities that have been created thus far
        unsigned int entityCounter;
    };

}