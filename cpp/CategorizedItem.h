//
// Created by Patrycja Wegrzynowicz on 18/10/2018.
//

#ifndef CPP_ITEMCATEGORY_H
#define CPP_ITEMCATEGORY_H

#include <memory>
#include "GildedRose.h"

class CategorizedItem {
protected:
    Item &item;

    explicit CategorizedItem(Item &item) : item(item) {}

public:
    using unique_ptr = ::std::unique_ptr<CategorizedItem>;

    virtual ~CategorizedItem() = default;

    virtual void updateItem() = 0;
};

class LegendaryItem : public CategorizedItem {
public:
    explicit LegendaryItem(Item &item) : CategorizedItem(item) {}

    void updateItem() override {}
};

class RegularItem : public CategorizedItem {
protected:
    void resetQuality();
    void increaseQuality();
    void decreaseQuality();

    bool hasExpired();

    virtual void updateQuality();
    virtual void updateSellIn();
    virtual void updateExpired();

public:
    explicit RegularItem(Item &item) : CategorizedItem(item) {}

    void updateItem() override;
};

class BackstagePassItem : public RegularItem {
    bool isCloseToConcert();
    bool isVeryCloseToConcert();

    void updateQuality() override;
    void updateExpired() override;
public:
    explicit BackstagePassItem(Item &item) : RegularItem(item) {}
};

class AgedCheeseItem : public RegularItem {
    void updateQuality() override;
    void updateExpired() override;

public:
    explicit AgedCheeseItem(Item &item) : RegularItem(item) {}
};


#endif //CPP_ITEMCATEGORY_H
