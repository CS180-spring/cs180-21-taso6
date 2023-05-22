#ifndef _LIST_H_
#define _LIST_H_

class List
{
private:
    vector<BirdRecord> collection
    string listName
    string username
public:
    List(/* args */);
    ~List();
    void createInstance();
    void editData();
    void getList();
    void editListName();
};

List::List(/* args */)
{
}

List::~List()
{
}



#endif