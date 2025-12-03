
#include "ticker.h"




// timer_ticker - continuously runs, returning true when set time is met
// returns false otherwise.

void one_tick_reset(OneTick& ot) {
    // one tick
    ot.one_tick_is_running = 0.0f;
    ot.one_tick_value = 0.0f;
    ot.one_tick_timer = 0.0f;
}

void one_tick_start(OneTick& ot) {
    ot.one_tick_is_running = true;
}

void one_tick_stop(OneTick& ot) {
    ot.one_tick_is_running = false;
}

void one_tick_set(OneTick& ot, const float time) {
    ot.one_tick_timer = time;
    ot.one_tick_value = SDL_GetTicks64() + time;
}

bool one_tick_done(OneTick& ot) {

    if (ot.one_tick_is_running) {
        if (SDL_GetTicks64() > ot.one_tick_timer) {
            one_tick_stop(ot);
            return true;
        }
    }
    return false;
}




// tickers
// timer_one_tick - upon setting to true, ticks for amount of milliseconds
// that was set. Returns false until time is met. Returns true when time is met, then stops.

void ticker_reset(Ticker& ticker) {
    ticker.ticker_is_running = false; // true - running, false - stopped
    ticker.ticker_value = 0.0f;
    ticker.ticker_timer = 0.0f;
}

void ticker_start(Ticker& ticker) {
    ticker.ticker_is_running = true;
}
void ticker_stop(Ticker& ticker) {
    ticker.ticker_is_running = false;
}

void ticker_set(Ticker& ticker, const float time) {
    ticker.ticker_value = time;
    ticker.ticker_timer = SDL_GetTicks64() + time;
}

bool ticker_update(Ticker& ticker) {

    if (ticker.ticker_is_running) {
        if (SDL_GetTicks64() > ticker.ticker_timer) {
            ticker_set(ticker, ticker.ticker_value);
            return true;
        }
    }
    return false;
}


