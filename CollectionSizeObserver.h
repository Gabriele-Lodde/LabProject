
#ifndef COLLECTIONSIZEOBSERVER_H
#define COLLECTIONSIZEOBSERVER_H
#include "Collection.h"
#include "Observer.h"


class CollectionSizeObserver : public Observer {
public:
    explicit CollectionSizeObserver(Collection* collection);
    ~CollectionSizeObserver();
    void update() override;
    int getLastSize() const;
private:
    Collection* collection;
    int lastSize;
};



#endif //COLLECTIONSIZEOBSERVER_H
