#include "GildedRose.h"

namespace {
    bool isBackstagePass(const Item &item) { return item.name == "Backstage passes to a TAFKAL80ETC concert"; }

    bool isBrie(const Item &item) { return item.name == "Aged Brie"; }

    bool isSulfurus(const Item &item) { return item.name == "Sulfuras, Hand of Ragnaros"; }

    bool hasExpired(const Item &item) { return item.sellIn < 0; }

    void updateExpired(Item &item) {
        if (isBrie(item)) {
            if (item.quality < 50) {
                item.quality = item.quality + 1;
            }
        } else if (isBackstagePass(item)) {
            item.quality = 0;
        } else if (isSulfurus(item)) {
            return;
        } else {
            if (item.quality > 0) {
                item.quality = item.quality - 1;
            }
        }

    }

    void updateSellIn(Item &item) {
        if (item.name != "Sulfuras, Hand of Ragnaros") {
            item.sellIn = item.sellIn - 1;
        }
    }

    void updateQuality(Item &item) {
        if (isBrie(item)) {
            if (item.quality < 50) {
                item.quality = item.quality + 1;
            }
        } else if (isBackstagePass(item)) {
            if (item.quality < 50) {
                item.quality = item.quality + 1;
            }

            if (item.sellIn < 11) {
                if (item.quality < 50) {
                    item.quality = item.quality + 1;
                }
            }

            if (item.sellIn < 6) {
                if (item.quality < 50) {
                    item.quality = item.quality + 1;
                }
            }
        } else if (isSulfurus(item)) {
            return;
        } else {
            if (item.quality > 0) {
                item.quality = item.quality - 1;
            }
        }
    }

    void updateItem(Item &item) {
        updateQuality(item);
        updateSellIn(item);
        if (hasExpired(item)) {
            updateExpired(item);
        }
    }

}

GildedRose::GildedRose(::std::vector<Item> const &items) : items(items) {}

GildedRose::GildedRose(::std::vector<Item> &&items) : items(::std::move(items)) {}

void GildedRose::updateQuality() {
    for (auto &item : items) {
        updateItem(item);
    }
}


