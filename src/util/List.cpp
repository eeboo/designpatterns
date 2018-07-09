//
// Created by ynakata on 09/07/2018.
//

#include "List.h"

template<class Item>
List<Item>::List(long size):itemCount(0), maxItems(size) {
    // dynamic allocate item be care full
    items = new Item[size];
}

template<class Item>
List<Item>::~List() {
    // free array allocation
    delete items;
}

/*
template<class Item>
List &List<Item>::operator=(const List &) {
    return <#initializer#>;
}
*/

template<class Item>
long List<Item>::size() const {
    return itemCount;
}

template<class Item>
Item & List<Item>::get(long index) {
    // Enforce precondition
    if ((index >= 0) && (index < itemCount)){
        return items[index];
    } else {
        throw 1;
    }
}

template<class Item>
void List<Item>::append(const Item & item) {
    bool ableToInsert = (itemCount < maxItems);
    if (ableToInsert){
        items[itemCount] = item;
        itemCount++;  // Increase count of entries
    } else {
        throw 2;
    }
}


template<class Item>
void List<Item>::remove(const Item & item) {
    long index = indexOf(item);
    if(index < 0){
        throw 3;
    } else {
        // shift all element from index to remove
        for(int i = index; index < itemCount; index ++){
            items[index] = items[index + 1];
        }
        //Decrement count
        itemCount--;
    }
}

template<class Item>
long List<Item>::indexOf(const Item &item) {
    for(long i = 0; i<itemCount; i++){
        Item currentItem = items[i];
        if(currentItem == item){
            return i;
        }
    }
    std::cout << "Hello world!" << std::endl;
    return -1;
}
