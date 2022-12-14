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
    void printByLocation(string location);
    double checkout(string cartNumber);
    void removeAllPurchased(string cartnumber);
};

class DepartmentStore
{
public:
    ItemList List;
    void Menu();
};

void DepartmentStore::Menu()
{
    while (true) {
        cout << "Welcome!" << endl;
        cout << "C - Clean store" << endl;
        cout << "I - Insert an item into the list" << endl;
        cout << "L - List by location" << endl;
        cout << "M - Move an item in the store" << endl;
        cout << "O - Checkout" << endl;
        cout << "P - Print all items in store" << endl;
        cout << "R - Remove all purchase" << endl;
        cout << "U - Update inventory system" << endl;
        cout << "Q - Exit the program." << endl;
        cout << "____________________" << endl;
        cout << "Select an Option to Perform :" << endl;
        string choice;
        cin >> choice;
        if (choice == "I" || choice == "i") {
            cout << "Enter the Product name: " << endl;
            string product_name;
            cin >> product_name;
            cout << "Enter the RFID :" << endl;
            string rfid;
            cin >> rfid;
            cout << "Enter the Orignal Location :" << endl;
            string location;
            cin >> location;
            cout << "Enter the Price :" << endl;
            double Price;
            cin >> Price;
            List.insertInfo(product_name, Price, rfid, location, "100");
        } else if(choice == "L" || choice == "l")
        {
            cout<<"Enter the Location:"<<endl;
            string location;
            cin >>location;
            List.printByLocation(location);
        } else if (choice == "M" || choice == "m")
        {
            cout << "Enter the RFID :" << endl;
            string rfid;
            cin >> rfid;
            cout << "Enter the Orignal Location :" << endl;
            string location;
            cin >> location;
            cout<< "Enter the new Location:"<<endl;
            string new_location;
            cin >> new_location;
            List.moveItem(rfid, location, new_location);
        } else if(choice == "O" || choice == "o")
        {
            cout << "Enter the cart Number :"<<endl;
            string cart;
            cin >> cart;
            List.checkout(cart);
        } else if (choice == "P" || choice == "p")
        {
            List.Display();
        } else if (choice == "R" || choice == "r")
        {
            cout << "Enter the cart Number :"<<endl;
            string  cart ;
            cin >> cart;
            List.removeAllPurchased(cart);
        } else if(choice == "Q" || choice == "q")
        {
            cout<<"Good Bye!!"<<endl;
            break;
        }
    }

}

void ItemList::removeAllPurchased(string cartnumber)
{
    ItemInfoNode *temp = this->Head;
    while(temp != NULL)
    {
        if(temp->get_Data().get_Current_location() == cartnumber)
        {
            if(temp == Head)
            {
                Head = temp->get_next();
            } else if(temp == Tail)
            {
                Tail = Tail->get_pre();
                Tail->set_next(NULL);
            } else
            {
                temp->get_next()->set_pre(temp->get_pre());
                temp->get_pre()->set_next(temp->get_next());
            }
        }
        temp = temp->get_next();
    }
}

double ItemList::checkout(string cartNumber)
{
    ItemInfoNode *temp = this->Head;
    double total_Amount =0;
    while (temp != NULL)
    {
        if(temp->get_Data().get_Current_location() == cartNumber)
        {
            temp->get_Data().set_Current_location("out");
            cout << "Item Name :" << temp->get_Data().get_Product_name() << endl;
            cout << "Price :" << temp->get_Data().get_Price() << endl;
            cout << "Rfid Number :" << temp->get_Data().get_RfidTagNumber() << endl;
            cout << "Orignal Location :" << temp->get_Data().get_Original_location() << endl;
            cout << "Current Location :" << temp->get_Data().get_Current_location() << endl;
            total_Amount += temp->get_Data().get_Price();
        }
        temp = temp->get_next();
    }
    cout<<"The total cost of your item is :"<< total_Amount<<endl;
    cout << "____________________________" << endl;

}

void ItemList::printByLocation(string location)
{
    ItemInfoNode *temp = this->Head;
    while(temp != NULL)
    {
        if(temp->get_Data().get_Current_location() == location)
        {
            cout << "Item Name :" << temp->get_Data().get_Product_name() << endl;
            cout << "Price :" << temp->get_Data().get_Price() << endl;
            cout << "Rfid Number :" << temp->get_Data().get_RfidTagNumber() << endl;
            cout << "Orignal Location :" << temp->get_Data().get_Original_location() << endl;
            cout << "Current Location :" << temp->get_Data().get_Current_location() << endl;
            cout << "_______" << endl;
        }
        temp = temp->get_next();
    }
}

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
//    ItemList t;
//    t.insertInfo("Jerry", 56, "A7C8B4E1F", "12345", "123");
//    t.insertInfo("Layz", 6, "0F999FCBA", "12345", "113");
//    t.removeAllPurchased("123");
////    t.insertInfo("Choco", 99, "A1111DDFF", "99345", "100");
////    t.insertInfo("Berry", 100, "00A5532FF", "99945", "999");
//   // t.moveItem("00A5532FF", "s99945", "105");
//   // t.printByLocation("c123");
//    t.removeAllPurchased("c123");
//
//    t.checkout("c123");
//
//    //t.checkout("c123");
//    t.Display();
DepartmentStore d;
d.Menu();
}