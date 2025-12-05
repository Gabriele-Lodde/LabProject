#include "CollectionSizeObserver.h"

CollectionSizeObserver::CollectionSizeObserver(Collection *collection) : collection(collection) {
    collection->addObserver(this);
}

CollectionSizeObserver::~CollectionSizeObserver() {
    collection->removeObserver(this);
}

void CollectionSizeObserver::update() {
    lastSize = collection->getSize();
}

int CollectionSizeObserver::getLastSize() const {
    return lastSize;
}
