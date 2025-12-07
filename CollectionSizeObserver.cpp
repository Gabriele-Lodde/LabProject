#include "CollectionSizeObserver.h"

#include <iostream>

CollectionSizeObserver::CollectionSizeObserver(Collection* collection) : collection(collection) {
    collection->addObserver(this);
}

void CollectionSizeObserver::update() {
    lastSize = collection->getSize();
    std::cout << "\n\033[1;33;40m[OBSERVER MESSAGE] Notes in the collection |" << collection->getName() << "| --> " << lastSize << "\033[0m" << std::endl;
}
