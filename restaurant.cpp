#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int code;
    int price;
    int quantity;
    string name;
    Item(int code, int price, int quantity, string name)
    {
        this->code = code;
        this->price = price;
        this->name = name;
        this->quantity = 10;
    }
};
class Restaurant
{
public:
    Item **items;
    Item **ordered_items;
    int total;
    int tax;
    int ordered_number_of_items;

    Restaurant(int total_items, int tax)
    {
        this->items = new Item *[total_items];
        this->total = 0;
        this->tax = tax;
    }
    void add(Item *item)
    {
        this->items[this->total++] = item;
    }
    Item *get(int code)
    {
        for (int i = 0; i < total; i++)
        {
            if (items[i]->code == code)
            {
                return items[i];
            }
        }
        return NULL;
    }
    void print_title(string title)
    {
        cout << "\n\t\t\t\t\t" << title << endl;
        cout << "\t\t\t\t    __________________\n\n";
    }
    void print_items(Item **all_items, int n)
    {
        cout << "Item Code\t\t\t\t"
             << "Item Name\t\t\t\t\t"
             << "Item Price\n";
        for (int i = 0; i < n; i++)
        {
            cout << all_items[i]->code << "\t\t\t\t\t" << all_items[i]->name << "\t\t\t\t" << all_items[i]->price << endl;
        }
    }
    void load_items(int total)
    {
        int price, code;
        string name;
        for (int i = 0; i < total; i++)
        {
            cin >> code;
            getline(cin, name);
            getline(cin, name);
            cin >> price;
            this->add(new Item(code, price, 10, name));
        }
    }
    void order_items()
    {
        int table, code, quantity;
        int total_price = 0;
        Item *item;
        cout << "Enter Table No : ";
        cin >> table;
        cout << "Enter Number of Items : ";
        cin >> this->ordered_number_of_items;
        this->ordered_items = new Item *[this->ordered_number_of_items];
        for (int i = 0; i < this->ordered_number_of_items; i++)
        {
            cout << "Enter Item " << i + 1 << " Code : ";
            cin >> code;
            cout << "Enter Quantity " << i + 1 << " Code : ";
            cin >> quantity;
            item = this->get(code);
            item->quantity = quantity;
            this->ordered_items[i] = item;
            total_price += item->price;
        }
        cout << endl;
        print_items(ordered_items, ordered_number_of_items);
        cout << "TAX";
        for (int i = 0; i < 11; i++)
            cout << "\t";
        cout << (double(total_price) / 100) * this->tax << " Taka";
        cout << "\n";

        for (int i = 0; i < 120; i++)
            cout << "_";
        cout << "\n";
        cout << "NET TOTAL";
        for (int i = 0; i < 10; i++)
            cout << "\t";
        cout << ((double(total_price) / 100) * this->tax) + total_price << " Taka";
    }
};
int main()
{
    int total = 12;
    Restaurant phitron = Restaurant(total, 5);
    phitron.load_items(total);
    phitron.print_title("MAKE BILL");
    phitron.print_items(phitron.items, total);
    phitron.print_title("BILL SUMMARY");
    phitron.order_items();
    // Item *x = phitron.get(171);

    return 0;
}