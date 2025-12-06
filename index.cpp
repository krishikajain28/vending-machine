#include <iostream>
#include <string>
using namespace std;

// vending machine question : making use of Inheritance, Polymorphism and my creativity ofcc
// this is the base class for the vending machine so that is knows about the drinks
class Drink
{
public:
    string name;
    double price;

    // application of destructor
    // making destructor so that it deletes the old memory and frees up the space when we later delete the temp object
    // also making the destructor virtual so that it points to the chlid classes and not this one
    // which means if we make a drink pointer that actually stores a water/cola/tea object,
    // then deleting that pointer will correctly call the destructor of the real object (child class)
    // instead of stopping at the base class
    // w/o virtual, only Drinks destructor runs
    // which causes incomplete cleanup and memory leaks when using polymorphism
    // virtual ensures correct destructor chain base → child

    virtual ~Drink() {}

    // later this will be over ridden as per the drink
    // ensuring TRUE POLYMORPHISM
    virtual void prepare()
    {
        cout << "Preparing drink..." << endl;
    }
};

// making use of Inheritance for individual drinks:
// why? so that child classes inherit the parent class's properties like name, price and set them differently
class Water : public Drink
{
public:
    Water(int type)
    {
        if (type == 1)
        {
            name = "Still Water";
            price = 1.00;
        }
        else
        {
            name = "Sparkling Water";
            price = 1.25; // making sparkling a lil more pricey
        }
    }

    void prepare() override
    {
        cout << "Filling bottle of " << name << endl;
    }
};

class CocaCola : public Drink
{
public:
    CocaCola(int type)
    {
        if (type == 1)
        {
            name = "Coca Cola (Regular)";
            price = 1.80;
        }
        else
        {
            name = "Coca Cola (Sugar-Free)";
            price = 1.90; // making sugar-free a lil more pricey
        }
    }

    void prepare() override
    {
        cout << "Dispensing chilled " << name << endl;
    }
};

class IcedTea : public Drink
{
public:
    IcedTea(int type)
    {
        if (type == 1)
        {
            name = "Peach Iced Tea";
            price = 2.20;
        }
        else
        {
            name = "Lemon Iced Tea";
            price = 2.20;
        }
    }

    void prepare() override
    {
        cout << "Serving chilled " << name << endl;
    }
};

// the main monitor handling the queries
class VendingMachine
{
public:
    double totalBill = 0.00;
    int order;

    void showDrinkList()
    {
        cout << "\n======== The Drinks List =========\n"
                "1. Water (Still)             $1.00 \n"
                "1. Water (Sparkling)         $1.25 \n"
                "2. Coca Cola (Regular)       $1.80 \n"
                "2. Coca Cola (Sugar-Free)    $1.90 \n"
                "3. Iced Tea (Peach)          $2.20 \n"
                "3. Iced Tea (Lemon)          $2.20 \n";
    }

    void placeOrders(double &currentBudget)
    {
        int order, type;

        for (int person = 1; person <= 3; person++)
        {

            // polymorphism - pointing to base class instead of the individual drinks
            Drink *myDrink = nullptr;

            if (person == 1)
            {
                cout << "\nKrishika is ordering now........";
            }
            else if (person == 2)
            {
                cout << "\nSimran is ordering now......";
            }
            else
            {
                cout << "\nNow it's your turn, Hritz...";
            }

            cout << "\n ====== Select Category ======       \n"
                    "1. Water (Still / Sparkling)           \n"
                    "2. Coca Cola (Regular / Sugar-Free)    \n"
                    "3. Iced Tea (Peach / Lemon)            \n"
                    "What would you like to order? (1,2,3): ";
            cin >> order;

            // asking for specific type of drink
            // here due to the concept of polymorphism, we can create different child classes w the help of
            // the parent class Drink and the nullptr we created

            if (order == 1)
            {
                cout << "1. Still\n2. Sparkling\nChoose your type(1,2) : ";
                cin >> type;

                myDrink = new Water(type); // creating water object
            }
            else if (order == 2)
            {
                cout << "1. Regular\n2. Sugar-Free\nChoose your type(1,2) : ";
                cin >> type;

                myDrink = new CocaCola(type); // creating cola object
            }
            else if (order == 3)
            {
                cout << "1. Peach\n2. Lemon\nChoose your type(1,2) : ";
                cin >> type;

                myDrink = new IcedTea(type); // creating tea object
            }
            else
            {
                cout << "Invalid choice made DUH.";
                continue; // this ensures code is not getting stopped because of some stupid inputs and gets skipped to the next person
            }

            // billing here
            if (myDrink != nullptr)
            {
                // because you can only buy your drink if you have money
                if (currentBudget >= myDrink->price)
                {
                    currentBudget -= myDrink->price;

                    // adding to the total bill here
                    totalBill += myDrink->price;

                    cout << endl;
                    // MAKING USE OF polymorphism
                    myDrink->prepare();
                    cout << "\nOrder prepared. " << endl;
                    cout << myDrink->name << " for: $" << myDrink->price << endl;
                    cout << "Remaining balance $" << currentBudget << endl;
                }
                else
                {
                    cout << "GAREEEBBBBBBB bye lol";
                }

                // v imp to clean up the memory
                delete myDrink;
            }
        }
    }

    void showTotalAndChange(double &currentBudget)
    {
        cout << "\n====== Bill Summary ======\n";
        cout << "Amount spent: $" << totalBill << endl;
        cout << "Amount left: $" << currentBudget << endl;
    }
};

int main()
{
    double initialBudget = 5;

    VendingMachine vm;

    cout << "\n========= Welcome to the Drink Vending Machine =========\n";

    int choice;
    do
    {
        cout << "\nMain menu: "
                "\n1.Show drink list "
                "\n2.Place Orders "
                "\n3.Show total & change "
                "\n4.Exit program "
                "\nWhat would you like to choose? (1,2,3,4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            vm.showDrinkList();
            break;
        case 2:
            vm.placeOrders(initialBudget);
            break;
        case 3:
            vm.showTotalAndChange(initialBudget);
            break;
        case 4:
            cout << "Exiting Program....\nThank you for coming! Have a nice day.";
            break;
        default:
            cout << "Invalid choice entered. Please try again.";
            break;
        }
    } while (choice != 4);
}
