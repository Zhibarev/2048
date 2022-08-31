#include "GameEventsEmitter.hh"

GameEventsEmitter &GameEventsEmitter::instance()
{
    static GameEventsEmitter emitter;
    return emitter;
}
