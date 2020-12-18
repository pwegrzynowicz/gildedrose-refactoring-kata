#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

std::string a = "Aged Brie";
std::string b = "Backstage passes to a TAFKAL80ETC concert";
std::string c = "Sulfuras, Hand of Ragnaros";

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != a && items[i].name != b && items[i].name != c)
        {
            if (items[i].quality > 0)
            {
                --items[i].quality;
            }
        }
        else if (items[i].quality < 50)
        {
            ++items[i].quality;

            if (items[i].name == b)
            {
                if (items[i].sellIn < 11)
                {
                    ++items[i].quality;
                }

                if (items[i].sellIn < 6)
                {
                    ++items[i].quality;
                }
            }
        }

        if (items[i].name != c)
        {
            --items[i].sellIn;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != a)
            {
                if (items[i].name != b)
                {
                    if (items[i].quality > 0 && items[i].name != c)
                    {
                      --items[i].quality;
                    }
                }
                else
                {
                    items[i].quality=0;
                }
            }
            else if (items[i].quality < 50)
            {
                ++items[i].quality;
            }
        }
    }
}
