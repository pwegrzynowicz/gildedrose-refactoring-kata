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
    virtual ~CategorizedItem() = default;

    virtual void updateItem() = 0;
};

class LegendaryItem : public CategorizedItem {
public:
    explicit LegendaryItem(Item &item) : CategorizedItem(item) {}

    void updateItem() override {}
};

class BasicItem : public CategorizedItem {
protected:
    void resetQuality();
    void increaseQuality();
    void decreaseQuality();

    bool hasExpired();

    virtual void updateQuality() = 0;
    virtual void updateSellIn();
    virtual void updateExpired() = 0;

    explicit BasicItem(Item &item) : CategorizedItem(item) {}

public:
    void updateItem() override;
};

class RegularItem : public BasicItem {
    void updateQuality() override;
    void updateExpired() override;

public:
    explicit RegularItem(Item &item) : BasicItem(item) {}
};

class BackstagePassItem : public BasicItem {
    bool isCloseToConcert();
    bool isVeryCloseToConcert();

    void updateQuality() override;
    void updateExpired() override;

public:
    explicit BackstagePassItem(Item &item) : BasicItem(item) {}
};

class AgedCheeseItem : public BasicItem {
    void updateQuality() override;
    void updateExpired() override;

public:
    explicit AgedCheeseItem(Item &item) : BasicItem(item) {}
};


#endif //CPP_ITEMCATEGORY_H
