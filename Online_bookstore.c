#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[100];
    int price;
    struct Book *left;
    struct Book *right;
} Book;


Book* create(char *title, char *author, int price) {              //it will create a new book node
    Book* new= (Book*)malloc(sizeof(Book));
    strcpy(new->title, title);
    strcpy(new->author, author);
    new->price = price;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Book* insertBook(Book *root, char *title, char *author, int price) {      // it will to insert a book into the BST
    if (root == NULL) {
        return create(title, author, price);
    }

    if (strcmp(title, root->title) < 0) {
        root->left = insertBook(root->left, title, author, price);
    } else if (strcmp(title, root->title) > 0) {
        root->right = insertBook(root->right, title, author, price);
    }

    return root;
}
Book* minValueNode(Book* node) {                 //  to find the minimum value node 
    Book* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
Book* deleteBook(Book* root, char* title) {   // to delete a book
    if (root == NULL) return root;

    if (strcmp(title, root->title) < 0) {
        root->left = deleteBook(root->left, title);
    } else if (strcmp(title, root->title) > 0) {
        root->right = deleteBook(root->right, title);
    } else {
        if (root->left == NULL) {
            Book *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Book *temp = root->left;
            free(root);
            return temp;
        }

        Book* temp = minValueNode(root->right);
        strcpy(root->title, temp->title);
        strcpy(root->author, temp->author);
        root->price = temp->price;
        root->right = deleteBook(root->right, temp->title);
    }
    return root;
}
Book* searchBook(Book* root, char* title) {      // it will  search for a book 
    if (root == NULL || strcmp(root->title, title) == 0)
        return root;

    if (strcmp(title, root->title) < 0)
        return searchBook(root->left, title);

    return searchBook(root->right, title);
}
void updateBook(Book* root, char* title, char* newauthor, int newprice) {     // function to update a book's information 
    Book* book = searchBook(root, title);
    if (book != NULL) {
        strcpy(book->author, newauthor);
        book->price = newprice;
    } else {
        printf("Book not found!\n");
    }
}
void inorder(Book *root) {                 // Function to print the BST 
    if (root != NULL) {
        inorder(root->left);
        printf("Title: %s, Author: %s, Price: %d\n", root->title, root->author, root->price);
        inorder(root->right);
    }
}

int main() {
    Book *root = NULL;
    int choice;
    char title[100], author[100];
    int price;
     printf("\n--------------: Welcome to the Bookstore :--------------\n");

    while (1) {
       
        printf("________________Online Bookstore Menu________________:\n");
        printf("                 1. Insert Book\n");
        printf("                 2. Delete Book\n");
        printf("                 3. Search Book\n");
        printf("                 4. Update Book\n");
        printf("                 5. Display Books\n");
        printf("                 6. Exit\n");
        printf("_______***__________________***________________***______\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf(" %[^\n]%*c", title); 
                printf("Enter author: ");
                scanf(" %[^\n]%*c", author);
                printf("Enter price: ");
                scanf("%d", &price);
                root = insertBook(root, title, author, price);
                break;

            case 2:
                printf("Enter title: ");
                scanf(" %[^\n]%*c", title);
                root = deleteBook(root, title);
                 printf("Book deleted");
                break;

            case 3:
                printf("Enter title: ");
                scanf(" %[^\n]%*c", title);
                Book* book = searchBook(root, title);
                if (book != NULL) {
                    printf("Book found - Title: %s, Author: %s, Price: %d\n", book->title, book->author, book->price);
                } else {
                    printf("Book not found!\n");
                }
                break;

            case 4:
                printf("Enter title of the book to update: ");
                scanf(" %[^\n]%*c", title);
                printf("Enter new author: ");
                scanf(" %[^\n]%*c", author);
                printf("Enter new price: ");
                scanf("%d", &price);
                updateBook(root, title, author, price);
                break;

            case 5:
                inorder(root);
                break;

            case 6:
             printf("--------------: THANKS FOR VISITING :--------------\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please enter valid option.\n");
        }
    }
    

      return 0;
}