#pragma once

#include <SDL2/SDL.h>

struct Ticker {
    // tickers
    // continuous ticker
    bool ticker_start_stop; // true - running, false - stopped
    float ticker_value;
    float ticker_timer;

    // one tick
    float one_tick_start_stop;
    float one_tick_value;
    float one_tick_timer;
};

void ticker_reset(Ticker& ticker);

void ticker_start_one_tick(Ticker& timer);
void ticker_stop_one_tick(Ticker& timer);
void ticker_set_one_tick(Ticker& timer, const float time);
bool ticker_one_tick(Ticker& timer);

void ticker_start(Ticker& timer);
void ticker_stop(Ticker& timer);
void ticker_set(Ticker& timer, const float time);
bool ticker_update(Ticker& timer);