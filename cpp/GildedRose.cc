#include <memory>

#include "GildedRose.h"
#include "CategorizedItem.h"

namespace {
    bool isBackstagePass(Item const &item) { return item.name == "Backstage passes to a TAFKAL80ETC concert"; }

    bool isBrie(Item const &item) { return item.name == "Aged Brie"; }

    bool isSulfurus(Item const &item) { return item.name == "Sulfuras, Hand of Ragnaros"; }

    ::std::unique_ptr<CategorizedItem> categorize(Item &item) {
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
        ::std::unique_ptr<CategorizedItem> categorized = categorize(item);
        categorized->updateItem();
    }
}


