#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct i {
    string productname;
    string producttype;
    double productprice = 0;
    int quantity = 0;
    double productamont = 0;
    int identity;

} i;

class supermarket {
private:
    struct node {
        int id;
        string proname, Job_title;
        double price, amount, salary;
        int quant;
        int volume;

        string type;
        int count = 0;
        node* next;
    };

public:
    node* head = NULL;
    node* front = NULL;
    node* rear = NULL;
    node* top = NULL;

    i item[100];

    void create();
    void display();
    void del();
    void modify();
    void create_store();
    void display_Store();
    void del_Store();
    void buy();
    void create_employees();
    void del_employees();
    void display_employees();
    void administrator();
    void employees();
    void store();

};

void supermarket::create() {
    node* new_node = new node;
    cout << "\nEnter product ID: ";
    cin >> new_node->id;
    cout << "Enter product type: ";
    cin >> new_node->type;
    cout << "\nEnter product name: ";
    cin >> new_node->proname;
    cout << "\nEnter product rate: ";
    cin >> new_node->price;
    cout << "\nEnter product stock: ";
    cin >> new_node->quant;

    if (head == NULL) {
        head = new_node;
        head->next = NULL;
    }
    else {
        node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        new_node->next = NULL;
        ptr->next = new_node;
    }
}

void supermarket::display() {
    cout << "\nTotal no. of products are: " << "\n";
    int t_id;

    if (head == NULL) {
        cout << "\nList is empty\n";
    }
    else {
        cout << "Enter product ID: ";
        cin >> t_id;
        node* ptr = head;
        cout << "Product ID\tProduct type\tProduct Name\t\tStock\tRate\n\n";
        while (ptr != NULL) {
            if (t_id == ptr->id) {
                cout << ptr->id << "\t\t" << ptr->type << "\t\t" << ptr->proname << "\t\t" << ptr->quant << "\t" << ptr->price << "\n";
            }
            ptr = ptr->next;
        }
    }
}

void supermarket::modify() {
    int t_id;

    if (head == NULL) {
        cout << "\nList is empty\n";
    }
    else {
        cout << "For modifying product enter its id: ";
        cin >> t_id;
        node* ptr = head;
        while (ptr != NULL) {
            if (t_id == ptr->id) {
                cout << "\nEnter new product ID: ";
                cin >> ptr->id;
                cout << "Enter new product type: ";
                cin >> ptr->type;
                cout << "\nEnter new product name: ";
                cin >> ptr->proname;
                cout << "\nEnter new product rate: ";
                cin >> ptr->price;
                cout << "\nEnter new product stock: ";
                cin >> ptr->quant;
                break;
            }
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            cout << "Product not found!!\n";
        }
    }
}

void supermarket::buy() {
    int n, ID, q, flag = 0, j = 0;
    int a;
    cout << "\nHow many products do you want to buy?";
    cin >> n;

    while (j < n) {
        cout << "\nEnter product ID: ";
        cin >> ID;
        cout << "Enter quantity: ";
        cin >> q;

        node* ptr = head;
        while (ptr != NULL) {
            if (ID == ptr->id) {
                if (q <= ptr->quant) {
                    a = ptr->price * q;
                    cout << "\nProduct ID: " << ptr->id << "\nProduct type: " << ptr->type << "\nProduct Name: " << ptr->proname << "\nQuantity: " << q << "\nPrice per product: " << ptr->price << "\nTotal Amount: " << a << "\n";
                    flag = 1;
                    item[j].productname = ptr->proname;
                    item[j].producttype = ptr->type;
                    item[j].productprice = ptr->price;
                    item[j].quantity = q;
                    item[j].productamont = a;
                    item[j].identity = ID;
                    ptr->quant = ptr->quant - q;
                    ptr->count = ptr->count + 1;
                    break;
                }
                else {
                    cout << "\nRequired Quantity not in stock!!";
                    flag = 1;
                    break;
                }
            }
            ptr = ptr->next;
        }

        if (flag == 0) {
            cout << "\nProduct ID not found!!";
        }

        j++;
    }

    if (flag == 1) {
        cout << "\n\nProduct available!!";
        cout << "\nProduct ID\tProduct type\tProduct Name\t\tQuantity\tRate\tTotal Amount\n\n";
        for (int k = 0; k < n; k++) {
            cout << item[k].identity << "\t\t" << item[k].producttype << "\t\t" << item[k].productname << "\t\t" << item[k].quantity << "\t\t" << item[k].productprice << "\t" << item[k].productamont << "\n";
        }
    }
}

void supermarket::del() {
    int t_id;
    if (head == NULL) {
        cout << "\nList is empty\n";
    }
    else {
        cout << "Enter product ID: ";
        cin >> t_id;
        node* temp1, * temp2;
        if (head->id == t_id) {
            temp1 = head;
            head = head->next;
            delete(temp1);
        }
        else {
            temp1 = head;
            temp2 = head->next;
            while (temp2 != NULL) {
                if (temp2->id == t_id) {
                    temp1->next = temp2->next;
                    delete(temp2);
                    break;
                }
                else {
                    temp1 = temp2;
                    temp2 = temp2->next;
                }
            }
            if (temp2 == NULL) {
                cout << "Product not found!!\n";
            }
        }
    }
}

void supermarket::create_employees() {
    node* new_node = new node;
    cout << "\nEnter employee ID: ";
    cin >> new_node->id;
    cout << "Enter employee job title: ";
    cin >> new_node->Job_title;
    cout << "\nEnter employee name: ";
    cin >> new_node->proname;
    cout << "\nEnter employee salary: ";
    cin >> new_node->salary;

    if (front == NULL) {
        front = new_node;
        rear = new_node;
        rear->next = front;
    }
    else {
        rear->next = new_node;
        rear = new_node;
        rear->next = front;
    }
}

void supermarket::del_employees() {
    int t_id;
    if (front == NULL) {
        cout << "\nList is empty\n";
    }
    else {
        cout << "Enter employee ID: ";
        cin >> t_id;
        node* temp1, * temp2;
        if (front->id == t_id) {
            temp1 = front;
            front = front->next;
            rear->next = front;
            delete(temp1);
        }
        else {
            temp1 = front;
            temp2 = front->next;
            while (temp2 != front) {
                if (temp2->id == t_id) {
                    temp1->next = temp2->next;
                    delete(temp2);
                    break;
                }
                else {
                    temp1 = temp2;
                    temp2 = temp2->next;
                }
            }
            if (temp2 == front) {
                cout << "Employee not found!!\n";
            }
        }
    }
}

void supermarket::display_employees() {
    if (front == NULL) {
        cout << "\nList is empty\n";
    }
    else {
        node* ptr = front;
        cout << "Employee ID\tEmployee Job Title\tEmployee Name\t\tEmployee Salary\n\n";
        while (ptr->next != front) {
            cout << ptr->id << "\t\t" << ptr->Job_title << "\t\t" << ptr->proname << "\t\t" << ptr->salary << "\n";
            ptr = ptr->next;
        }
        cout << ptr->id << "\t\t" << ptr->Job_title << "\t\t" << ptr->proname << "\t\t" << ptr->salary << "\n";
    }
}

void supermarket::administrator() {
    int choice;

    while (1) {
        cout << "\n--------------------------";
        cout << "\n\tADMINISTRATOR MENU\n";
        cout << "--------------------------\n";
        cout << "1. Create product\n";
        cout << "2. Display specific product\n";
        cout << "3. Modify product\n";
        cout << "4. Delete product\n";
        cout << "5. Buy product\n";
        cout << "8. Exit\n";
        cout << "--------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            del();
            break;
        case 5:
            buy();
            break;

        case 0:
            return;
        default:
            cout << "\nInvalid choice!!";
        }
    }
}

void supermarket::employees() {
    int choice;

    while (1) {
        cout << "\n--------------------------";
        cout << "\n\tEMPLOYEE MENU\n";
        cout << "--------------------------\n";
        cout << "1. Create employee\n";
        cout << "2. Display employees\n";
        cout << "3. Delete employee\n";

        cout << "0. Exit\n";
        cout << "--------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            create_employees();
            break;
        case 2:
            display_employees();
            break;
        case 3:
            del_employees();
            break;
        case 0:
            return;
        default:
            cout << "\nInvalid choice!!";
        }
    }
}
void supermarket::create_store() {
    node* new_node = new node;
    cout << "\nEnter product ID: ";
    cin >> new_node->id;
    cout << "\nEnter product name: ";
    cin >> new_node->proname;
    cout << "\nEnter volume: ";
    cin >> new_node->volume;

    if (top == NULL) {
        top = new_node;
        new_node->next = NULL;
    }
    else {
        new_node->next = top;
        top = new_node;
    }
}

void supermarket::display_Store() {
    node* curr = top;
    cout << "Product ID\t\tProduct Name\t\tVolume\n";
    while (curr != NULL) {
        cout << curr->id << "\t\t\t" << curr->proname << "\t\t\t" << curr->volume << "\n";
        curr = curr->next;
    }
}

void supermarket::del_Store() {
    if (top == NULL) {
        cout << "Stack underflow\n";
    }
    else {
        node* delptr = top;
        top = delptr->next;
        delete delptr;
    }
}
void supermarket::store() {
    int choice;

    while (1) {
        cout << "\n--------------------------";
        cout << "\n\tstore MENU\n";
        cout << "--------------------------\n";
        cout << "1. Create store\n";
        cout << "2. Display store\n";
        cout << "3. Delete store\n";
        cout << "0. Exit\n";
        cout << "--------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            create_store();
            break;
        case 2:
            display_Store();
            break;
        case 3:
            del_Store();
            break;
        case 0:
            return;
        default:
            cout << "\nInvalid choice!!";
        }
    }
};

int main() {
    supermarket s;
    int choice;

    while (1) {
        cout << "\n--------------------------";
        cout << "\n\tSUPERMARKET MENU\n";
        cout << "--------------------------\n";
        cout << "1. Administrator\n";
        cout << "2. Employee\n";
        cout << "3. store\n";
        cout << "0. Exit\n";
        cout << "--------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.administrator();
            break;
        case 2:
            s.employees();
            break;
        case 3:
            s.store();
            break;
        case 0:
            exit(0);
        default:
            cout << "\nInvalid choice!!";
        }
    }

    return 0;
}