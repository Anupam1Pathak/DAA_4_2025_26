#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Book
{
    int id;
    string title;
    string author;
    Book *next;
};

// Linked List class
class Library
{
private:
    Book *head;

public:
    Library()
    {
        head = NULL;
    }

    // Add Book
    void addBook(int id, string title, string author)
    {
        Book *newBook = new Book();
        newBook->id = id;
        newBook->title = title;
        newBook->author = author;
        newBook->next = NULL;

        if (head == NULL)
        {
            head = newBook;
        }
        else
        {
            Book *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newBook;
        }

        cout << "Book added successfully!\n";
    }

    // Display Books
    void displayBooks()
    {
        if (head == NULL)
        {
            cout << "Library is empty.\n";
            return;
        }

        Book *temp = head;
        cout << "\n--- Book List ---\n";
        while (temp != NULL)
        {
            cout << "ID: " << temp->id << endl;
            cout << "Title: " << temp->title << endl;
            cout << "Author: " << temp->author << endl;
            cout << "----------------------\n";
            temp = temp->next;
        }
    }

    // Search Book by ID
    void searchByID(int id)
    {
        Book *temp = head;
        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << "Book Found!\n";
                cout << "Title: " << temp->title << endl;
                cout << "Author: " << temp->author << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found.\n";
    }

    // Search Book by Title
    void searchByTitle(string title)
    {
        Book *temp = head;
        while (temp != NULL)
        {
            if (temp->title == title)
            {
                cout << "Book Found!\n";
                cout << "ID: " << temp->id << endl;
                cout << "Author: " << temp->author << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found.\n";
    }

    // Delete Book
    void deleteBook(int id)
    {
        if (head == NULL)
        {
            cout << "Library is empty.\n";
            return;
        }

        Book *temp = head;
        Book *prev = NULL;

        // If head needs to be deleted
        if (temp != NULL && temp->id == id)
        {
            head = temp->next;
            delete temp;
            cout << "Book deleted successfully!\n";
            return;
        }

        while (temp != NULL && temp->id != id)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Book not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Book deleted successfully!\n";
    }
};

// Main UI
int main()
{
    Library lib;
    int choice, id;
    string title, author;

    do
    {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Search Book by Title\n";
        cout << "5. Delete Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            lib.addBook(id, title, author);
            break;

        case 2:
            lib.displayBooks();
            break;

        case 3:
            cout << "Enter Book ID: ";
            cin >> id;
            lib.searchByID(id);
            break;

        case 4:
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            lib.searchByTitle(title);
            break;

        case 5:
            cout << "Enter Book ID to delete: ";
            cin >> id;
            lib.deleteBook(id);
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}