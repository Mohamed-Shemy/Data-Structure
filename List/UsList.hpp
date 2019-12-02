#define MAX_ITEM 100
class UsList
{
public:
    UsList();
    void clear();
    bool isFull();
    bool isEmpty();
    void insert(char newItem);
    bool remove(char item);
    void reset();
    char next();
    int  Length();
private:
    char letters [MAX_ITEM];
    int curPos;
    int length;
};