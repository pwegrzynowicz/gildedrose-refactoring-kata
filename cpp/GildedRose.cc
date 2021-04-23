#include "GildedRose.h"

namespace {
    bool isBackstagePass(const Item& item) { return item.name == "Backstage passes to a TAFKAL80ETC concert"; }

    bool isBrie(const Item& item) { return item.name == "Aged Brie"; }

    bool isSulfurus(const Item& item) { return item.name == "Sulfuras, Hand of Ragnaros"; }

    void increaseQuality(Item& item);

    void decreaseQuality(Item& item);

    void decreaseQuality(Item& item) {
        if (item.quality > 0) {
            item.quality = item.quality - 1;
        }
    }

    void increaseQuality(Item& item) {
        if (item.quality < 50) {
            item.quality = item.quality + 1;
        }
    }

    bool isVeryCloseToConcert(const Item& item) { return item.sellIn < 6; }

    bool isCloseToConcert(const Item& item) { return item.sellIn < 11; }

    void updateBackstagePassQuality(Item& item) {
        increaseQuality(item);
        if (isCloseToConcert(item)) {
            increaseQuality(item);
        }
        if (isVeryCloseToConcert(item)) {
            increaseQuality(item);
        }
    }

    void updateQuality(Item& item) {
        if (isBrie(item)) {
            increaseQuality(item);
        } else if (isBackstagePass(item)) {
            updateBackstagePassQuality(item);
        } else if (isSulfurus(item)) {
            return;
        } else {
            decreaseQuality(item);
        }
    }

    void updateSellIn(Item& item) {
        if (isSulfurus(item)) return;
        item.sellIn = item.sellIn - 1;
    }

    bool hasExpired(const Item& item) { return item.sellIn < 0; }

    void updateExpired(Item& item) {
        if (isBrie(item)) {
            increaseQuality(item);
        } else if (isBackstagePass(item)) {
            item.quality = 0;
        } else if (isSulfurus(item)) {
            return;
        } else {
            decreaseQuality(item);
        }
    }

    void updateItem(Item& item) {
        updateQuality(item);
        updateSellIn(item);
        if (hasExpired(item)) {
            updateExpired(item);
        }
    }

}

GildedRose::GildedRose(::std::vector<Item> const& items) : items(items) {}

GildedRose::GildedRose(::std::vector<Item>&& items) : items(::std::move(items)) {}

void GildedRose::updateQuality() {
    for (auto& item : items) {
        updateItem(item);
    }
}


