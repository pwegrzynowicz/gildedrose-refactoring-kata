#include <memory>
#include <map>
#include <unordered_map>

#include "GildedRose.h"
#include "ItemStrategy.h"

namespace {
    using item_strategy_ptr = ::std::unique_ptr<ItemStrategy>;
    using item_strategies_map = ::std::unordered_map<::std::string, item_strategy_ptr>;

    item_strategies_map initializeItemStrategies() {
        item_strategies_map ret;
        ret["Sulfuras, Hand of Ragnaros"] = ::std::make_unique<LegendaryItemStrategy>();
        ret["Aged Brie"] = ::std::make_unique<AgedCheeseStrategy>();
        ret["Backstage passes to a TAFKAL80ETC concert"] = ::std::make_unique<BackstagePassStrategy>();
        return ret;
    }

    ItemStrategy& findItemStrategy(Item& item) {
        static item_strategies_map ITEM_STRATEGIES = initializeItemStrategies();
        static item_strategy_ptr DEFAULT_STRATEGY = ::std::make_unique<RegularItemStrategy>();
        auto found = ITEM_STRATEGIES.find(item.name);
        return found == ITEM_STRATEGIES.end() ? *DEFAULT_STRATEGY : *found->second;
    }
}

Item::Item(::std::string _name, int _sellIn, int _quality) : name(::std::move(_name)), sellIn(_sellIn),
                                                             quality(_quality) {}

void Item::resetQuality() {
    quality = 0;
}

void Item::increaseQuality() {
    if (quality < 50) {
        quality++;
    }
}

void Item::decreaseQuality() {
    if (quality > 0) {
        quality--;
    }
}

bool Item::hasExpired() const {
    return sellIn < 0;
}

GildedRose::GildedRose(::std::vector<Item> const& items) : items(items) {}

GildedRose::GildedRose(::std::vector<Item>&& items) : items(::std::move(items)) {}

void GildedRose::updateQuality() {
    for (auto& item : items) {
        ItemStrategy& itemStrategy = findItemStrategy(item);
        itemStrategy.updateItem(item);
    }
}

