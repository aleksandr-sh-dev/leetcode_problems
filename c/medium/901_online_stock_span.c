#define MAX_PRICES 10000

typedef struct {
    int prices[MAX_PRICES];
    int spans[MAX_PRICES];
    int curr_price_idx;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner *spanner = malloc(sizeof(StockSpanner));
    spanner->curr_price_idx = 0;
    return spanner;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1; // the price itself
    while (obj->curr_price_idx > 0 && price >= obj->prices[obj->curr_price_idx]) {
        span += obj->spans[obj->curr_price_idx];
        obj->curr_price_idx--;
    }

    obj->prices[++obj->curr_price_idx] = price;
    obj->spans[obj->curr_price_idx] = span;

    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/