#pragma once

#include "Precompiled.hpp"
#include "UserEvents.hpp"

#include "Common/StateMachine.hpp"

// Forward declarations.
class Logger;
class ConsoleSystem;
class ConsoleHistory;
class ConsoleFrame;
class CoreRenderer;
class ShapeRenderer;
class TextRenderer;
class FrameCounter;

class Texture;
class Font;

class BaseFrame;

//
// Console Definitions
//

namespace Console
{
    // Window settings.
    extern ConsoleVariable windowName;
    extern ConsoleVariable windowWidth;
    extern ConsoleVariable windowHeight;
    extern ConsoleVariable windowResize;

    // Render settings.
    extern ConsoleVariable renderVsync;
}

//
// Main Context
//

namespace Main
{
    // Context methods.
    bool Initialize();
    void Cleanup();

    void SendEvent(UserEvents::Type type);

    void Quit();

    // Context accessors.
    bool            IsInitialized();
    bool            IsQuitting();
    std::string     WorkingDir();

    Logger&         Logger();
    ConsoleSystem&  ConsoleSystem();
    ConsoleHistory& ConsoleHistory();
    ConsoleFrame&   ConsoleFrame();
    CoreRenderer&   CoreRenderer();
    ShapeRenderer&  ShapeRenderer();
    TextRenderer&   TextRenderer();
    FrameCounter&   FrameCounter();

    Texture&        BlankTexture();
    Font&           DefaultFont();

    SDL_Window*     SystemWindow();
    SDL_GLContext   GraphicsContext();
    FT_Library      FontLibrary();

    BaseFrame&      MainFrame();
}
