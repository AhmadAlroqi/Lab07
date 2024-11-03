#include <stdio.h>
#include <string.h>

typedef struct {
    int bookID;
    char title[100];
    char author[50];
    int year;
    float price;
} Book;

void addBook() {
    FILE *file = fopen("books.dat", "ab");
    Book newBook;
    printf("Enter book details:\n");
    printf("ID: ");
    scanf("%d", &newBook.bookID);
    printf("Title: ");
    scanf(" %[^\n]", newBook.title);
    printf("Author: ");
    scanf(" %[^\n]", newBook.author);
    printf("Year: ");
    scanf("%d", &newBook.year);
    printf("Price: ");
    scanf("%f", &newBook.price);
    fwrite(&newBook, sizeof(Book), 1, file);
    fclose(file);
}
void displayBooks() {
    FILE *file = fopen("books.dat", "rb");
    Book book;
    while (fread(&book, sizeof(Book), 1, file)) {
        printf("ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f\n", book.bookID, book.title, book.author, book.year, book.price);
    }
    fclose(file);
}
void calculateTotalValue() {
    FILE *file = fopen("books.dat", "rb");
    Book book;
    float total = 0;
    while (fread(&book, sizeof(Book), 1, file)) {
        total += book.price;
    }
    printf("Total Value of Books: %.2f\n", total);
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        printf("1. Add Book\n2. Display Books\n3. Calculate Total Value\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) addBook();
        else if (choice == 2) displayBooks();
        else if (choice == 3) calculateTotalValue();
        else if (choice == 4) break;
    }

    return 0;
}

