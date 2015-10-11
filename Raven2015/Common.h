#pragma once

#define ERRORSTR_AUDIO_TYPE_UNINIT "Error: uninitialized audio type encountered."
#define ERRORSTR_AUDIO_OPERATION_UNINT "Error: uninitialized audio operation encountered."
#define ERRORSTR_AUDIO_NO_RECORD "Error: Attempting to perform non-loading operation on a new audio resource."
#define FPS_30_TICK_TIME 0.0333333333333f
#define FPS_60_TICK_TIME 0.0166666666666f
#define SOUNDMAP_T std::map<std::string, std::shared_ptr<sf::SoundBuffer>>
#define MUSICMAP_T std::map<std::string, std::shared_ptr<sf::Music>>
#define NO_ACTION_STR "NO ACTION"

#include <iostream>
#include "entityx\config.h"
#include "tinyxml2.h"

using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using namespace tinyxml2;

namespace ex = entityx;

namespace Raven {

    namespace Common {

        // An enumeration type detailing the types of processable audio files.
        enum EAudioType { NO_TYPE, SOUND, MUSIC };

        // An enumeration type detailing the possible operations for audio files.
        enum EAudioOperation { NO_AUDIO_OPERATION, AUDIO_LOAD, AUDIO_UNLOAD, AUDIO_PLAY, AUDIO_PAUSE, AUDIO_STOP };

        // An enumeration type detailing the possible operations for timers.
        enum ETimerOperation { NO_TIMER_OPERATION, TIMER_START, TIMER_PAUSE, TIMER_RESTART, TIMER_SCAN, TIMER_REMOVE, TIMER_ADD };

        // An enumeration type detailing how a loop state should be assigned.
        enum ELoop { LOOP_FALSE, LOOP_TRUE, LOOP_UNCHANGED };

        // A specification of the ELoop type for audio resources only
        typedef ELoop EAudioLoop;

        /* 
         * An enumeration type detailing a set of macro render-sorting layers.
         * NO_LAYER     = "null" value
         * Background   = Objects that exist in the back of the game space (typically environmental)
         * Foreground   = Objects that exist in the main game space
         * HUD          = Objects that exist overlaying the game space
         * GUI          = Objects associated with the game's menu system, super-ceding all others
         */
        enum ELayer { NO_LAYER, Background, Foreground, HUD, GUI };

        // A specification of the ELayer type for Rendering assets only
        typedef ELayer ERenderingLayer;

        // A standard pixel-based unit of measurement for the x-axis
        static const float STD_UNITX = 64.0f;

        // A standard pixel-based unit of measurement for the y-axis
        static const float STD_UNITY = 64.0f;

        // The size of borders for imported spritesheets, in pixels
        static const int BORDER_PADDING = 2;

        // The size of borders for sprites within imported spritesheets, in pixels
        static const int SHAPE_PADDING = 2;

        // Helper function for clamping primitives between two values (used in animations)
        template <typename T>
        void clamp(T &toClamp, T min, T max) {
            if (toClamp < min) {
                toClamp = min;
            }
            if (toClamp > max) {
                toClamp = max;
            }
        }

        class Serializable {
        public:
            // Default Null Constructor
            Serializable() {}

            // Primary enforcement of abstract class
            virtual ~Serializable() = 0;

            // Allow the ISerializable to output an XML string representation of its properties
            std::string(*serialize)();

            // Allow the ISerializable to assign new values to its properties via an XML string
            void(*deserialize)(std::string &xml);
        };

        // Create a static wrapper for the various preset GUI window types
        struct GUIWidgetNames {
            const static std::string MASTER_WINDOW;     // The name of the top-level widget container
            const static std::string MASTER_TABLE;      // The name of the table organizing the layout
            const static std::string SCENE_HIERARCHY;   // The name for the list of named entities present in the scene
            const static std::string COMPONENT_LIST;    // The name for the list of possible components to add to an entity
            const static std::string TEXTURE_LIST;      // The name for the list of textures to be used in the game
            const static std::string MUSIC_LIST;        // The name for the list of music to be used in the game
            const static std::string SOUND_LIST;        // The name for the list of sounds to be used in the game
            const static std::string FONT_LIST;         // The name for the list of fonts to be used in the game
            const static std::string CONTENT;           // The name for the tabbed notebook containing the usable assets
            const static std::string TOOLBAR;           // The name for the horizontal box containing the button Brushes for the editor
            const static std::string ENTITY_DESIGNER;   // The name for the window which displays information about the selected entity
            const static std::string PREFAB_LIST;       // The name for the list of currently defined prefabs
            const static std::string CANVAS;            // The name for the view into the scene 
        };

        struct GUIWidgetTypes {
            const static std::string WIDGET;            // The name of the base abstract Widget class
            const static std::string WINDOW;            // The name of the single-Widget container class
            const static std::string BOX;               // The name of the multi-Widget container class with a specified orientation
            const static std::string TABLE;             // The name of the multi-Widget container class with a specified layout
            const static std::string CANVAS;            // The name of the special Widget that can be drawn to with SFML
            const static std::string BUTTON;            // The name of the Widget that can be clicked to trigger an action
        };

        struct CollisionLayerSettings {
            const static std::string SOLID;             // The layer that indicates the entities should be "pushed out of each other"
            const static std::string TRIGGER;           // The layer that indicates the entity will react to the collision
        };

        // The default position/dimensions of our various windows
        const int WINDOW_XPOS = 20;
        const int WINDOW_YPOS = 20;
        const float WINDOW_WIDTH = 1200;
        const float WINDOW_HEIGHT = 800;
        const float MAIN_GUI_WINDOW_PADDING = 100;

        const size_t TABLE_ROWS = 6;
        const size_t TABLE_COLUMNS = 5;
        const float TABLE_EDGE_PADDING = 50.f;

        const int SCENE_HIERARCHY_XPOS = 0;
        const int SCENE_HIERARCHY_YPOS = 0;
        //const float SCENE_HIERARCHY_WIDTH = 

        //const int CANVAS_XPOS = 
        const float CANVAS_WIDTH = 600;
        const float CANVAS_HEIGHT = 400;



    };

}

namespace cmn = Raven::Common;
namespace rvn = Raven;
