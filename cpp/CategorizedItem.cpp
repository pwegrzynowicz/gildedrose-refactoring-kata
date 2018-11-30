//
// Created by Patrycja Wegrzynowicz on 18/10/2018.
//

#include "CategorizedItem.h"

void RegularItem::resetQuality() {
    item.quality = 0;
}

void RegularItem::increaseQuality() {
    if (item.quality < 50) {
        item.quality++;
    }
}

void RegularItem::decreaseQuality() {
    if (item.quality > 0) {
        item.quality--;
    }
}

bool RegularItem::hasExpired() {
    return item.sellIn < 0;
}

// Template Method
void RegularItem::updateItem() {
    updateQuality();
    updateSellIn();
    if (hasExpired()) {
        updateExpired();
    }
}

void RegularItem::updateQuality() {
    decreaseQuality();
}

void RegularItem::updateSellIn() {
    item.sellIn--;
}

void RegularItem::updateExpired() {
    decreaseQuality();
}

void BackstagePassItem::updateQuality() {
    increaseQuality();
    if (isCloseToConcert()) {
        increaseQuality();
    }
    if (isVeryCloseToConcert()) {
        increaseQuality();
    }
}

void BackstagePassItem::updateExpired() {
    resetQuality();
}

bool BackstagePassItem::isCloseToConcert() {
    static const int HOT_PERIOD_IN_DAYS = 6;
    return item.sellIn < HOT_PERIOD_IN_DAYS;
}

bool BackstagePassItem::isVeryCloseToConcert() {
    static const int VERY_HOT_PERIOD_IN_DAYS = 11;
    return item.sellIn < VERY_HOT_PERIOD_IN_DAYS;
}

void AgedCheeseItem::updateQuality() {
    increaseQuality();
}

void AgedCheeseItem::updateExpired() {
    increaseQuality();
}

