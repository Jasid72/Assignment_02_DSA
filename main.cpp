#include <iostream>

using namespace std;

class ItemInfo
{
private:
    string product_name;
    double price;
    string rfidTagNumber;
    string Original_location;
    string Current_location;

public:
    void set_Product_name(string product_name)
    {
        this->product_name = product_name;
    }
    string get_Product_name() { return this->product_name; }
    void set_price(double price) { this->price = price; }
    double get_Price() { return this->price; }
    void set_RfidTagNumber(string rfidTagNumber)
    {
        if (rfidTagNumber.length() == 9)
        {
            if (rfidTagNumber >= "A" && rfidTagNumber <= "F" || rfidTagNumber >= "0" && rfidTagNumber <= "9")
            {
                this->rfidTagNumber = rfidTagNumber;
            }
            else
            {
                cout << " Put 9 characters" << endl;
            }
        }
    }
    string get_RfidTagNumber() { return this->rfidTagNumber; }
    void set_Original_location(string Original_location)
    {
        if (Original_location.length() == 5)
        {
            this->Original_location = "s" + Original_location;
        }
        else if (Original_location.length() == 6 && Original_location[0] == 's')
        {
            this->Original_location = Original_location;
        }
        else
        {
            cout << "Enter Valid Original location" << endl;
        }
    }
    string get_Original_location() { return this->Original_location; }
    void set_Current_location(string Cur_loc)
    {
        if (Cur_loc.length() == 3)
        {
            this->Current_location = "c" + Cur_loc;
        }
        else if (Cur_loc.length() == 4 && Cur_loc[0] == 'c')
        {
            this->Current_location = Cur_loc;
        }
        else
        {
            cout << "Enter Valid Current Location" << endl;
        }
    }
    string get_Current_location() { return this->Current_location; }
    ItemInfo() {}
    ItemInfo(string product_name, double price, string rfidTagNumber,
        string Original_location, string Current_location)
    {
        this->set_Product_name(product_name);
        this->set_price(price);
        this->set_RfidTagNumber(rfidTagNumber);
        this->set_Original_location(Original_location);
        this->set_Current_location(Current_location);
    }
};

class ItemInfoNode
{
private:
    ItemInfoNode* pre;
    ItemInfoNode* next;
    ItemInfo data = {};

public:
    void set_next(ItemInfoNode* next) { this->next = next; }
    ItemInfoNode* get_next() { return next; }

    void set_pre(ItemInfoNode* pre) { this->pre = pre; }
    ItemInfoNode* get_pre() { return pre; }
    void set_Data(ItemInfo i) {
    this->data.set_Product_name(i.get_Product_name());
    this->data.set_RfidTagNumber(i.get_RfidTagNumber());
    this->data.set_price(i.get_Price());
    this->data.set_Original_location(i.get_Original_location());
    this->data.set_Current_location(i.get_Current_location());
    }

    ItemInfo get_Data()
    {
        return this->data;
    }
    ItemInfoNode()
    {
        pre = NULL;
        next = NULL;
    }
    ItemInfoNode(string product_name, double price,
        string rfidTagNumber, string Original_location,
        string Current_location)
    {
        next = NULL;
        pre = NULL;
        data.set_Product_name(product_name);
        data.set_price(price);
        data.set_RfidTagNumber(rfidTagNumber);
        data.set_Original_location(Original_location);
        data.set_Current_location(Current_location);
    }
};

class ItemList
{
private:
    ItemInfoNode* Head = NULL;
    ItemInfoNode* Tail = NULL;
    int length = 0;

public:
    ItemList() {}
    void insertInfo(string product_name, double price, string rfidTagNumber,
        string Original_location, string Current_location);
    void Display();
    void moveItem(string UserrfidTagNumber, string old_location, string newlocation);
};

void ItemList::insertInfo(string product_name, double price,
    string rfidTagNumber, string Original_location,
    string Current_location)
{
    ItemInfoNode* N1 = new ItemInfoNode(product_name, price, rfidTagNumber, Original_location, Current_location);
    if (Head == NULL)
    {
        Head = N1;
    }
    else
    {
        ItemInfoNode* temp = Head;
        while (temp->get_next() != NULL)
        {
            temp = temp->get_next();
        }
        N1->set_pre(temp);
        temp->set_next(N1);
        length++;
    }
}

void ItemList::moveItem(string UserrfidTagNumber, string old_location, string newlocation)
{
    ItemInfoNode* temp = this->Head;
    while (temp != NULL)
    {

        if (temp->get_Data().get_RfidTagNumber() == UserrfidTagNumber)
        {
            if (temp->get_Data().get_Original_location() == old_location)
            {
                ItemInfo obj = temp->get_Data();
                obj.set_Current_location(newlocation);
                temp->set_Data(obj);
                //temp->get_Data().set_Current_location(newlocation);
                break;
            }
            else
            {
                cout << "Not working" << endl;
            }
        }
        else
        {
            cout << "Your Rfid Number is Not Match." << endl;
        }
        temp = temp->get_next();
    }
}

void ItemList::Display()
{
    ItemInfoNode* temp = Head;
    if (temp == NULL)
    {
        cout << "Empty List" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << "Item Name :" << temp->get_Data().get_Product_name() << endl;
            cout << "Price :" << temp->get_Data().get_Price() << endl;
            cout << "Rfid Number :" << temp->get_Data().get_RfidTagNumber() << endl;
            cout << "Orignal Location :" << temp->get_Data().get_Original_location() << endl;
            cout << "Current Location :" << temp->get_Data().get_Current_location() << endl;
            cout << "_______" << endl;
            temp = temp->get_next();
        }
    }
    cout << endl;
}

int main()
{
    ItemList t;
    t.insertInfo("Jerry", 56, "A7C8B4E1F", "12345", "123");
    t.insertInfo("Layz", 6, "0F999FCBA", "12345", "113");
    t.insertInfo("Choco", 99, "A1111DDFF", "99345", "100");
    t.insertInfo("Berry", 100, "00A5532FF", "99945", "999");
    t.moveItem("00A5532FF", "s99945", "105");
    t.Display();
}