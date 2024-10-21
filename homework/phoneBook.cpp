#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;

struct Contact {
    string firstName;
    string lastName;
    string mobileNo;
    string gender;
    string address;

    void display() const {
        // Display contact 
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|| " << setw(16) << left << firstName
             << "|| " << setw(16) << left << lastName
             << "|| " << setw(16) << left << mobileNo
             << "|| " << setw(16) << left << gender
             << "|| " << setw(16) << left << address
             << "||" << endl;
        cout << "------------------------------------------------------------------------------------------------" << endl;
    }

    string toString() const {
        return firstName + "," + lastName + "," + mobileNo + "," + gender + "," + address;
    }

    static Contact fromString(const string& str) {
        Contact contact;
        size_t start = 0, end = str.find(',');
        contact.firstName = str.substr(start, end - start);

        start = end + 1;
        end = str.find(',', start);
        contact.lastName = str.substr(start, end - start);

        start = end + 1;
        end = str.find(',', start);
        contact.mobileNo = str.substr(start, end - start);

        start = end + 1;
        end = str.find(',', start);
        contact.gender = str.substr(start, end - start);

        contact.address = str.substr(end + 1);
        return contact;
    }
};


string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t");
    if (start == string::npos) return "";
    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

class PhoneBook {
private:
    map<string, Contact> contactsByMobileNo;
    vector<Contact> contactsByName;

    bool isValidMobileNo(const string& mobileNo) const {
        return mobileNo.length() == 10 && all_of(mobileNo.begin(), mobileNo.end(), ::isdigit);
    }

    bool isValidGender(const string& gender) const {
        return all_of(gender.begin(), gender.end(), ::isalpha) && !gender.empty();
    }

    bool isNonEmpty(const string& str) const {
        return !str.empty();
    }

    void loadContactsFromFile(const string& filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            Contact contact = Contact::fromString(line);
            contactsByMobileNo[contact.mobileNo] = contact;
        }
        file.close();
        updateContactsByName();
    }

    void saveContactsToFile(const string& filename) const {
        ofstream file(filename);
        for (const auto& pair : contactsByMobileNo) {
            file << pair.second.toString() << endl;
        }
        file.close();
    }

    void updateContactsByName() {
        contactsByName.clear();
        for (const auto& pair : contactsByMobileNo) {
            contactsByName.push_back(pair.second);
        }
        sort(contactsByName.begin(), contactsByName.end(), [](const Contact& a, const Contact& b) {
            if (a.lastName != b.lastName) return a.lastName < b.lastName;
            return a.firstName < b.firstName;
        });
    }

public:
    PhoneBook() {
        loadContactsFromFile("contacts.txt");
    }

    ~PhoneBook() {
        saveContactsToFile("contacts.txt");
    }

    void addContact() {
        Contact contact;
        string input;

        while (true) {
            cout << "Enter First Name: ";
            getline(cin, input);
            contact.firstName = trim(input);
            if (contact.firstName.empty()) {
                cout << "You missed to give First Name. Please try again." << endl;
                continue;
            }

            cout << "Enter Last Name: ";
            getline(cin, input);
            contact.lastName = trim(input);
            if (contact.lastName.empty()) {
                cout << "You missed to give Last Name. Please try again." << endl;
                continue;
            }

            cout << "Enter Mobile No (10 digits): ";
            getline(cin, input);
            contact.mobileNo = trim(input);
            if (!isValidMobileNo(contact.mobileNo)) {
                cout << "Enter a valid mobile number (10 digits only)! Please try again." << endl;
                continue;
            }

            cout << "Enter Gender (e.g., Male/Female): ";
            getline(cin, input);
            contact.gender = trim(input);
            if (!isValidGender(contact.gender)) {
                cout << "Enter a valid gender (alphabetic characters only)! Please try again." << endl;
                continue;
            }

            cout << "Enter Address: ";
            getline(cin, input);
            contact.address = trim(input);
            if (contact.address.empty()) {
                cout << "You missed to give Address. Please try again." << endl;
                continue;
            }

            if (contactsByMobileNo.find(contact.mobileNo) != contactsByMobileNo.end()) {
                cout << "A contact with this mobile number already exists." << endl;
                continue;
            }

            contactsByMobileNo[contact.mobileNo] = contact;
            updateContactsByName();
            cout << "Contact added successfully!" << endl;
            break;
        }
    }

    void searchContactByName() const {
        string firstName, lastName;
        cout << "Enter First Name: ";
        getline(cin, firstName);
        firstName = trim(firstName);
        if (firstName.empty()) {
            cout << "You missed to give First Name. Please try again." << endl;
            return;
        }

        cout << "Enter Last Name: ";
        getline(cin, lastName);
        lastName = trim(lastName);
        if (lastName.empty()) {
            cout << "You missed to give Last Name. Please try again." << endl;
            return;
        }

        string lowerFirstName = toLower(firstName);
        string lowerLastName = toLower(lastName);

        bool found = false;
        for (const auto& contact : contactsByName) {
            if (toLower(contact.firstName) == lowerFirstName && toLower(contact.lastName) == lowerLastName) {
                cout << "Contact found:" << endl;
                contact.display();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Contact not found." << endl;
        }
    }

    void updateContact() {
        string mobileNo;
        cout << "Enter Mobile No to update: ";
        getline(cin, mobileNo);
        mobileNo = trim(mobileNo);

        auto it = contactsByMobileNo.find(mobileNo);
        if (it != contactsByMobileNo.end()) {
            Contact& contact = it->second;
            string input;

            while (true) {
                cout << "Enter new First Name (current: " << contact.firstName << "): ";
                getline(cin, input);
                contact.firstName = trim(input);
                if (contact.firstName.empty()) {
                    cout << "You missed to give First Name. Please try again." << endl;
                    continue;
                }

                cout << "Enter new Last Name (current: " << contact.lastName << "): ";
                getline(cin, input);
                contact.lastName = trim(input);
                if (contact.lastName.empty()) {
                    cout << "You missed to give Last Name. Please try again." << endl;
                    continue;
                }

                cout << "Enter new Gender (current: " << contact.gender << "): ";
                getline(cin, input);
                contact.gender = trim(input);
                if (!isValidGender(contact.gender)) {
                    cout << "Enter a valid gender (alphabetic characters only)! Please try again." << endl;
                    continue;
                }

                cout << "Enter new Address (current: " << contact.address << "): ";
                getline(cin, input);
                contact.address = trim(input);
                if (contact.address.empty()) {
                    cout << "You missed to give Address. Please try again." << endl;
                    continue;
                }

                updateContactsByName();
                cout << "Contact updated successfully!" << endl;
                break;
            }
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void deleteContact() {
        string mobileNo;
        cout << "Enter Mobile No to delete: ";
        getline(cin, mobileNo);
        mobileNo = trim(mobileNo);

        auto it = contactsByMobileNo.find(mobileNo);
        if (it != contactsByMobileNo.end()) {
            contactsByMobileNo.erase(it);
            updateContactsByName();
            cout << "Contact deleted successfully!" << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void displayContacts() const {
        if (contactsByMobileNo.empty()) {
            cout << "No contacts available." << endl;
            return;
        }

        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "|| First Name       | Last Name        | Mobile No        | Gender           | Address          ||" << endl;
        cout << "-------------------------------------------------------------------------------------------------" << endl;
        for (const auto& contact : contactsByName) {
            cout << "|| " << setw(16) << left << contact.firstName
                 << "|| " << setw(16) << left << contact.lastName
                 << "|| " << setw(16) << left << contact.mobileNo
                 << "|| " << setw(16) << left << contact.gender
                 << "|| " << setw(16) << left << contact.address
                 << "||" << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;

    while (true) {
        cout<<endl<<endl;
        cout<< "******************** Phone Book Menu:*****************" <<endl;
        cout << "*                                                   *"  << endl;
        cout << "*               1. Add Contact                      *"<< endl;
        cout << "*               2. Search Contact by Name           *" << endl;
        cout << "*               3. Update Contact                   *" << endl;
        cout << "*               4. Delete Contact                   *" << endl;
        cout << "*               5. Display All Contacts             *" << endl;
        cout << "*               6. Exit                             *" << endl;
        cout << "*                                                   *"  << endl;
        cout << "*****************************************************"  << endl;
        cout << "   => Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore newline character left in the input buffer

        switch (choice) {
            case 1:
                phoneBook.addContact();
                break;
            case 2:
                phoneBook.searchContactByName();
                break;
            case 3:
                phoneBook.updateContact();
                break;
            case 4:
                phoneBook.deleteContact();
                break;
            case 5:
                phoneBook.displayContacts();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
