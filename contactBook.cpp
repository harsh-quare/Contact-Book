#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

struct Node {
    string name;
    long long int phone_number;
    Node* next;
    Node* prev;
};

class contactBook {
private:
    Node* head;
    string x;
    long long int y;

public:
    contactBook() {
        head = NULL;
        x = "";
        y = 0;
    }

    void createNode() {
        if (head == NULL) {
            Node* newNode = new Node;
            cout << "Enter Contact Name: ";
            cin.ignore(); // To handle whitespace in input
            getline(cin, x);
            newNode->name = x;

            cout << "Enter Phone Number: ";
            cin >> y;
            newNode->phone_number = y;

            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;

            cout << "Contact Added Successfully." << endl;
        } else {
            Node* newNode = new Node;
            cout << "Enter Contact Name: ";
            cin.ignore(); // To handle whitespace in input
            getline(cin, x);
            newNode->name = x;

            cout << "Enter Phone Number: ";
            cin >> y;
            newNode->phone_number = y;

            newNode->next = NULL;

            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;

            cout << "Contact Added Successfully." << endl;
        }
    }

    void Display() {
        Node* temp = head;
        int count = 0; // Number of contacts

        if (temp == NULL) {
            cout << "Contact List is empty. Please add new contacts." << endl;
        } 
        else {
            BubbleSort();
            cout << "Name" << "           Phone Number\n" << endl;

            while (temp != NULL) {
                count++;
                cout << temp->name;
                cout << "          " << temp->phone_number << endl;
                temp = temp->next;
            }

            cout << "Total Contacts: " << count << endl;
        }
    }

    int Search() {
        bool check = false;
        Node* temp = head;

        cout << "************" << endl;
        cout << "Search Options:\n";
        cout << "1. Search by Name\n";
        cout << "2. Search by Phone Number\n";

        int command;
        cout << "Enter your choice: ";
        cin >> command;

        if (command == 1 && temp != NULL) {
            cout << "Enter the name to search: ";
            cin.ignore(); // To handle whitespace in input
            getline(cin, x);
            while (temp != NULL) {
                if (temp->name == x) {
                    cout << "************" << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Phone Number: " << temp->phone_number << endl;
                    cout << "************" << endl;
                    check = true;
                    break;
                }
                temp = temp->next;
            }

            if (!check) {
                cout << "Contact not found." << endl;
            }
        } 
        
        else if (command == 2) {
            cout << "Enter the phone number to search: ";
            cin >> y;

            while (temp != NULL) {
                if (temp->phone_number == y) {
                    cout << "************" << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Phone Number: " << temp->phone_number << endl;
                    cout << "************" << endl;
                    check = true;
                    break;
                }
                temp = temp->next;
            }

            if (!check) {
                cout << "Contact not found." << endl;
            }
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
        return check ? 1 : 0;
    }

    void DeleteAllContacts() {
        Node* temp = head;
        Node* temp2 = NULL;

        if (head == NULL) {
            cout << "Contact book is empty. No contacts to delete." << endl;
        } 
        else {
            while (temp != NULL) {
                temp2 = temp;
                temp = temp->next;
                delete temp2;
            }
            head = NULL;
            cout << "All contacts deleted successfully." << endl;
        }
    }

    int DeleteContactBySearch() {
        Node* temp = head;
        cout << "************" << endl;
        cout << "Delete Options:\n";
        cout << "1. Delete by Name\n";
        cout << "2. Delete by Phone Number\n";

        int command;
        cout << "Enter your choice: ";
        cin >> command;

        if (command == 1) {
            bool Dcheck = false;
            cout << "Enter the name to delete: ";
            cin.ignore(); // To handle whitespace in input
            getline(cin, x);
            while (temp != NULL) {
                if (temp->name == x) {
                    cout << "************" << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Phone Number: " << temp->phone_number << endl;
                    cout << "************" << endl;
                    Dcheck = true;
                    break;
                }
                temp = temp->next;
            }

            if (Dcheck) {
                int command;
                cout << "Press 1 to confirm deletion: ";
                cin >> command;

                if (command == 1 && temp == head) {
                    Node* temp1 = NULL;
                    temp1 = temp;
                    temp = temp->next;
                    delete temp1;

                    if (temp != NULL) {
                        temp->prev = NULL;
                    }
                    head = temp;
                    cout << "Contact deleted successfully." << endl;
                } 
                else if (command == 1 && temp->next == NULL) {
                    temp->prev->next = NULL;
                    delete temp;
                    cout << "Contact deleted successfully." << endl;
                } 
                else if (command == 1) {
                    Node* temp1 = NULL;
                    temp1 = temp;
                    temp->prev->next = temp1->next;
                    temp->next->prev = temp1->prev;
                    delete temp1;
                    cout << "Contact deleted successfully." << endl;
                } 
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            } 
            
            else {
                cout << "Contact not found." << endl;
            }
        } 
        
        else if (command == 2) {
            bool Dcheck = false;
            cout << "Enter the phone number to delete: ";
            cin >> y;

            while (temp != NULL) {
                if (temp->phone_number == y) {
                    cout << "************" << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Phone Number: " << temp->phone_number << endl;
                    cout << "************" << endl;
                    Dcheck = true;
                    break;
                }
                temp = temp->next;
            }

            if (Dcheck) {
                int command;
                cout << "Press 1 to confirm deletion: ";
                cin >> command;

                if (command == 1 && temp == head) {
                    Node* temp1 = NULL;
                    temp1 = temp;
                    temp = temp->next;
                    delete temp1;

                    if (temp != NULL) {
                        temp->prev = NULL;
                    }
                    head = temp;
                    cout << "Contact deleted successfully." << endl;
                } 
                else if (command == 1 && temp->next == NULL) {
                    temp->prev->next = NULL;
                    delete temp;
                    cout << "Contact deleted successfully." << endl;
                } 
                else if (command == 1) {
                    Node* temp1 = NULL;
                    temp1 = temp;
                    temp->prev->next = temp1->next;
                    temp->next->prev = temp1->prev;
                    delete temp1;
                    cout << "Contact deleted successfully." << endl;
                } 
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            } 
            
            else {
                cout << "Contact not found." << endl;
            }
        } 
        
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
        return 0;
    }

    void BubbleSort() {
        Node* temp = head;
        Node* i = NULL;
        Node* j = NULL;

        string n;
        long long int n2;

        if (temp == NULL) {
            cout << "Contact list is empty." << endl;
        } 
        else {
            for (i = head; i->next != NULL; i = i->next) {
                for (j = i->next; j != NULL; j = j->next) {
                    if (i->name > j->name) {
                        n = i->name;
                        i->name = j->name;
                        j->name = n;

                        n2 = i->phone_number;
                        i->phone_number = j->phone_number;
                        j->phone_number = n2;
                    }
                }
            }
        }
    }

    int EditContacts() {
        Node* temp = head;
        cout << "***********" << endl;
        cout << "Edit Options:\n";
        cout << "1. Edit by Name\n";
        cout << "2. Edit by Phone Number\n";

        int command;
        cout << "Enter your choice: ";
        cin >> command;

        if (command == 1) {
            bool Echeck = false;
            cout << "Enter the name to edit: ";
            cin.ignore(); // To handle whitespace in input
            getline(cin, x);
            while (temp != NULL) {
                if (temp->name == x) {
                    cout << "************" << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Phone Number: " << temp->phone_number << endl;
                    cout << "************" << endl;
                    Echeck = true;
                    break;
                }
                temp = temp->next;
            }

            if (Echeck) {
                int command;
                cout << "Press 1 to edit contact: ";
                cin >> command;

                if (command == 1) {
                    cout << "Enter new name: ";
                    cin.ignore(); // To handle whitespace in input
                    getline(cin, x);
                    temp->name = x;

                    cout << "Enter new phone number: ";
                    cin >> y;
                    temp->phone_number = y;

                    cout << "Contact updated successfully." << endl;
                } 
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            } 
            
            else {
                cout << "Contact not found." << endl;
            }
        } 
        
        else if (command == 2) {
            bool Echeck = false;
            cout << "Enter the phone number to edit: ";
            cin >> y;

            while (temp != NULL) {
                if (temp->phone_number == y) {
                    cout << "************" << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Phone Number: " << temp->phone_number << endl;
                    cout << "************" << endl;
                    Echeck = true;
                    break;
                }
                temp = temp->next;
            }

            if (Echeck) {
                int command;
                cout << "Press 1 to edit contact: ";
                cin >> command;

                if (command == 1) {
                    cout << "Enter new name: ";
                    cin.ignore(); // To handle whitespace in input
                    getline(cin, x);
                    temp->name = x;

                    cout << "Enter new phone number: ";
                    cin >> y;
                    temp->phone_number = y;

                    cout << "Contact updated successfully." << endl;
                } 
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            } 
            else {
                cout << "Contact not found." << endl;
            }
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
        return 0;
    }
};

int main() {
    contactBook obj;

    cout << "What is Your Name: ";
    string user_name;
    getline(cin, user_name);
    cout << "***********" << endl;
    cout << user_name << ", Welcome to Contacts" << endl;
    cout << "***********" << endl;

    while (1) {
        cout << "***********" << endl;
        cout << "1. Add Contact\n";
        cout << "2. Edit Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. Search Contact\n";
        cout << "5. Display All Contacts\n";
        cout << "6. Delete All Contacts\n";
        cout << "***********" << endl;

        int command;
        cout << "Enter your choice: ";
        cin >> command;

        switch (command) {
            case 1:
                obj.createNode();
                break;
            case 2:
                obj.EditContacts();
                break;
            case 3:
                obj.DeleteContactBySearch();
                break;
            case 4:
                obj.Search();
                break;
            case 5:
                obj.Display();
                break;
            case 6:
                obj.DeleteAllContacts();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
