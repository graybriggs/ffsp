
#include "ticker.h"


void ticker_reset(Ticker& ticker) {
    ticker.ticker_start_stop = false; // true - running, false - stopped
    ticker.ticker_value = 0.0f;
    ticker.ticker_timer = 0.0f;

    // one tick
    ticker.one_tick_start_stop = 0.0f;
    ticker.one_tick_value = 0.0f;
    ticker.one_tick_timer = 0.0f;
}

// tickers
// timer_one_tick - upon setting to true, ticks for amount of milliseconds
// that was set. Returns false until time is met. Returns true when time is met, then stops.

void ticker_start_one_tick(Ticker& ticker) {
    ticker.one_tick_start_stop = true;
}

void ticker_stop_one_tick(Ticker& ticker) {
    ticker.one_tick_start_stop = false;
}

void ticker_set_one_tick(Ticker& ticker, const float time) {
    ticker.one_tick_timer = time;
    ticker.one_tick_value = SDL_GetTicks64() + time;
}

bool ticker_one_tick_done(Ticker& ticker) {

    if (ticker.one_tick_start_stop) {
        if (SDL_GetTicks64() > ticker.one_tick_timer) {
            ticker_stop_one_tick(ticker);
            return true;
        }
    }
    return false;
}


// timer_ticker - continuously runs, returning true when set time is met
// returns false otherwise.

void ticker_start(Ticker& ticker) {
    ticker.ticker_start_stop = true;
}
void ticker_stop(Ticker& ticker) {
    ticker.ticker_start_stop = false;
}

void ticker_set(Ticker& ticker, const float time) {
    ticker.ticker_value = time;
    ticker.ticker_timer = SDL_GetTicks64() + time;
}

bool ticker_update(Ticker& ticker) {

    if (ticker.ticker_start_stop) {
        if (SDL_GetTicks64() > ticker.ticker_timer) {
            ticker_set(ticker, ticker.ticker_value);
            return true;
        }
    }
    return false;
}