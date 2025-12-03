#pragma once

#include <SDL2/SDL.h>

struct Ticker {
    // tickers
    // continuous ticker
    bool ticker_is_running; // true - running, false - stopped
    float ticker_value;
    float ticker_timer;
};

struct OneTick {
    // one tick
    float one_tick_is_running;
    float one_tick_value;
    float one_tick_timer;
};

void ticker_reset(Ticker& ticker);
void ticker_start(Ticker& timer);
void ticker_stop(Ticker& timer);
void ticker_set(Ticker& timer, const float time);
bool ticker_update(Ticker& timer);


void one_tick_reset(OneTick& ot);
void one_tick_start(OneTick& ot);
void one_tick_stop(OneTick& ot);
void one_tick_set(OneTick& ot, const float time);
bool one_tick_done(OneTick& ot);
