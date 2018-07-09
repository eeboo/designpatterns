//
// Created by ynakata on 09/07/2018.
//

#ifndef DESIGNPATTERNS_LIST_H
#define DESIGNPATTERNS_LIST_H

template <class Item>
class List {
public:

    List(long size = DEFAULT_CAPACITY);

    /**
     * Override the default copy constructor so that member data are initialized properly.
     */
    //List(List&);

    /**
     * Frees the list's internal data structures but not the elements in the list. The class is not designed for subclassing;
     * the destructor is not virtual
     */
    ~List();

    /**
     * Implements the assignement operation to assign member data properly.
     * @return
     */
    //List& operator =(const List&);

    /**
     * Return the number of objects in the list.
     * @return
     */
    long size() const;

    /**
     * Return the object at the given index
     * @param index
     * @return
     */
    Item & get(long index);

    /**
     * Adds the element in the list, making it the last element.
     */
    void append(const Item & item);

    /**
     * Return the index of the element in the list if found
     * Otherwise return -1
     * @param item
     * @return
     */
    long indexOf(const Item & item);

    /**
     * Removes the given element from the list.
     * This operation requires that the type of elements in the list support the == operator for comparison.
     */
    void remove(const Item&);

private:

    /**
     * Default capacity of the list
     */
    static const int MAX_CAPACITY = 256;
    /**
     * Default capacity of the list
     */
    static const int DEFAULT_CAPACITY = 64;

    /**
     * Array of list items (ignore items[0]
     */
    Item *items;

    /**
     * Current count of list items
     */
    int itemCount;

    /**
     * maxItems
     */
    int maxItems;
};


#endif //DESIGNPATTERNS_LIST_H
