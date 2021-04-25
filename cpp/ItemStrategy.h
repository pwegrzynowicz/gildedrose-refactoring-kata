#ifndef CPP_ITEMCATEGORY_H
#define CPP_ITEMCATEGORY_H

#include <memory>
#include "GildedRose.h"

class ItemStrategy {
public:
    virtual ~ItemStrategy() = default;
    virtual void updateItem(Item& item) = 0;
};

class LegendaryItemStrategy : public ItemStrategy {
public:
    void updateItem(Item& item) override {}
};

class BasicItemStrategy : public ItemStrategy {
protected:
    virtual void updateQuality(Item& item) = 0;
    virtual void updateSellIn(Item& item);
    virtual void updateExpired(Item& item) = 0;

public:
    void updateItem(Item& item) override;
};

class RegularItemStrategy : public BasicItemStrategy {
protected:
    void updateQuality(Item& item) override;
    void updateExpired(Item& item) override;
};

class BackstagePassStrategy : public BasicItemStrategy {
protected:
    bool isCloseToConcert(Item& item);
    bool isVeryCloseToConcert(Item& item);

    void updateQuality(Item& item) override;
    void updateExpired(Item& item) override;
};

class AgedCheeseStrategy : public BasicItemStrategy {
protected:
    void updateQuality(Item& item) override;
    void updateExpired(Item& item) override;
};


#endif //CPP_ITEMCATEGORY_H
