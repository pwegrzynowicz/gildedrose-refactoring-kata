#include <memory>

#include "GildedRose.h"
#include "CategorizedItem.h"

namespace {
    bool isBackstagePass(const Item &item) { return item.name == "Backstage passes to a TAFKAL80ETC concert"; }

    bool isBrie(const Item &item) { return item.name == "Aged Brie"; }

    bool isSulfurus(const Item &item) { return item.name == "Sulfuras, Hand of Ragnaros"; }

    CategorizedItem::unique_ptr categorize(Item &item) {
        if (isBrie(item)) {
            return ::std::make_unique<AgedCheeseItem>(item);
        } else if (isSulfurus(item)) {
            return ::std::make_unique<LegendaryItem>(item);
        } else if (isBackstagePass(item)) {
            return ::std::make_unique<BackstagePassItem>(item);
        }
        return ::std::make_unique<RegularItem>(item);
    }
}

GildedRose::GildedRose(::std::vector<Item> const &items) : items(items) {}

GildedRose::GildedRose(::std::vector<Item> &&items) : items(::std::move(items)) {}

void GildedRose::updateQuality() {
    for (auto &item : items) {
        CategorizedItem::unique_ptr categorized = categorize(item);
        categorized->updateItem();
    }
}


