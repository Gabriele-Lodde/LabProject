
#ifndef COLLECTIONSIZEOBSERVER_H
#define COLLECTIONSIZEOBSERVER_H
#include "Collection.h"
#include "Observer.h"


class CollectionSizeObserver : public Observer {
public:
    explicit CollectionSizeObserver(Collection* collection);
    void update() override;
private:
    Collection* collection;
    int lastSize{0};
};



#endif //COLLECTIONSIZEOBSERVER_H
