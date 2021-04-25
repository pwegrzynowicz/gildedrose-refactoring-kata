#ifndef CPP_GILDEDROSE_H
#define CPP_GILDEDROSE_H

#include <string>
#include <vector>

class Item {
public:
    ::std::string name;
    int sellIn;
    int quality;

    Item(::std::string _name, int _sellIn, int _quality);

    void resetQuality();

    void increaseQuality();

    void decreaseQuality();

    bool hasExpired() const;
};

class GildedRose {
public:
    ::std::vector<Item> items;

    explicit GildedRose(::std::vector<Item>&& items);

    explicit GildedRose(::std::vector<Item> const& items);

    void updateQuality();
};

#endif
