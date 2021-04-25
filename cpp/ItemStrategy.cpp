#include "ItemStrategy.h"

// Template Method
void BasicItemStrategy::updateItem(Item& item) {
    updateQuality(item);
    updateSellIn(item);
    if (item.hasExpired()) {
        updateExpired(item);
    }
}

void BasicItemStrategy::updateSellIn(Item& item) {
    item.sellIn--;
}

void RegularItemStrategy::updateQuality(Item& item) {
    item.decreaseQuality();
}

void RegularItemStrategy::updateExpired(Item& item) {
    item.decreaseQuality();
}

void BackstagePassStrategy::updateQuality(Item& item) {
    item.increaseQuality();
    if (isCloseToConcert(item)) {
        item.increaseQuality();
    }
    if (isVeryCloseToConcert(item)) {
        item.increaseQuality();
    }
}

void BackstagePassStrategy::updateExpired(Item& item) {
    item.resetQuality();
}

bool BackstagePassStrategy::isCloseToConcert(Item& item) {
    return item.sellIn < 6;
}

bool BackstagePassStrategy::isVeryCloseToConcert(Item& item) {
    return item.sellIn < 11;
}

void AgedCheeseStrategy::updateQuality(Item& item) {
    item.increaseQuality();
}

void AgedCheeseStrategy::updateExpired(Item& item) {
    item.increaseQuality();
}

