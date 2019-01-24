//
// Created by Patrycja Wegrzynowicz on 18/10/2018.
//

#include "CategorizedItem.h"

void BasicItem::resetQuality() {
    item.quality = 0;
}

void BasicItem::increaseQuality() {
    if (item.quality < 50) {
        item.quality++;
    }
}

void BasicItem::decreaseQuality() {
    if (item.quality > 0) {
        item.quality--;
    }
}

bool BasicItem::hasExpired() {
    return item.sellIn < 0;
}

// Template Method
void BasicItem::updateItem() {
    updateQuality();
    updateSellIn();
    if (hasExpired()) {
        updateExpired();
    }
}

void BasicItem::updateSellIn() {
    item.sellIn--;
}


void RegularItem::updateQuality() {
    decreaseQuality();
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
    return item.sellIn < 6;
}

bool BackstagePassItem::isVeryCloseToConcert() {
    return item.sellIn < 11;
}

void AgedCheeseItem::updateQuality() {
    increaseQuality();
}

void AgedCheeseItem::updateExpired() {
    increaseQuality();
}

