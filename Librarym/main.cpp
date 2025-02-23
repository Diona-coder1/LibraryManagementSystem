#include "FileHandler.h"
#include <iostream>

using namespace std;

int main()
{

	FileHandler fileHandler;
	string filename = "books.txt";

	int choice;
	const int MAX_BOOKS = 100;
	string books[MAX_BOOKS];
	int count = 0;

	do
	{
		cout << "\nLIBRARY MANAGEMENT SYSTEM \n";
		cout << "1.Save books to file\n";
		cout << "2.Load books from file\n";
		cout << "3.Exit\n";
		cout << "Choose an option: ";
		cin >> choice;
		cin.ignore(); // Ignore newline

		switch (choice)
		{

		case 1:
		{ // Save book
			int numBooks;
			cout << "Enter the number of books to save: ";
			cin >> numBooks;
			cin.ignore();

			string *newBooks = new string[numBooks];
			for (int i = 0; i < numBooks; i++)
			{
				cout << "Enter book " << (i + 1) << ": ";
				getline(cin, newBooks[i]);
			}
			fileHandler.saveToFile(filename, newBooks, numBooks);
			cout << "Books saved successfully!\n";
			delete[] newBooks; // Free memory
			break;
		}
		case 2:
		{ // Load books
			count = fileHandler.loadFromFile(filename, books, MAX_BOOKS);
			if (count == 0)
			{
				cout << "No books found in the file!\n";
			}
			else
			{
				cout << "Loaded " << count << " books:\n";
				for (int i = 0; i < count; i++)
				{
					cout << "- " << books[i] << endl;
				}
			}
			break;
		}
		case 3:
		{ // Exit
			cout << "Exiting Library System. Goodbye!\n";
			break;
		}
		default:
			cout << "Invalid choice! Please select a valid option.\n";
		}
	} while (choice != 3); // Keep running until user exits

	return 0;
}
