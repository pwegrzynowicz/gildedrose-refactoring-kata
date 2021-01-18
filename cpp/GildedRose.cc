#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name == "Sulfuras, Hand of Ragnaros")
        {
            if (items[i].quality < 50)
                items[i].quality++;
        }
        else if (items[i].name == "Aged Brie" || items[i].name == "Backstage passes to a TAFKAL80ETC concert")
        {
            if (items[i].quality < 50)
            {
                items[i].quality = items[i].quality + 1;
                if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
                {   
                    if (items[i].sellIn < 11)
                    {
                        items[i].quality = items[i].quality + 1;
                    }
                    if (items[i].sellIn < 6)
                    {
                        items[i].quality = items[i].quality + 1;
                    }
                }
                else
                    if (items[i].sellIn < 0)]
                        items[i].quality++;
            }
        }
        else
        {
            if (items[i].quality > 0)
            {
                items[i].quality = items[i].quality - 1;
            }
            items[i].sellIn = items[i].sellIn - 1;
            if (items[i].sellIn < 0)
            {
                if (items[i].name != "Aged Brie")
                {
                    if (items[i].name != "Backstage passes to a TAFKAL80ETC concert")
                    {
                        if (items[i].quality > 0)
                        {
                            items[i].quality = items[i].quality - 1;
                        }
                    }
                    else
                    {
                        items[i].quality = items[i].quality - items[i].quality;
                    }
                }
                else
                {
                    if (items[i].quality < 50)
                    {
                        items[i].quality = items[i].quality + 1;
                    }
                }
            }
        }
        if (items[i].sellIn < 0 && items[i].name == "Backstage passes to a TAFKAL80ETC concert")
            items[i].quality = 0;
    }
}
