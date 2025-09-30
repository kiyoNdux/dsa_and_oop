import java.util.Scanner;

class Book {
    String title;
    String author;
    int year;

    // default constructor ask user for input
    Book() {
        Scanner userInput = new Scanner(System.in);
        System.out.print("Enter book title: ");
        title = userInput.nextLine();
        System.out.print("Enter author name: ");
        author = userInput.nextLine();
        System.out.print("Enter publication year: ");
        year = userInput.nextInt();
    }

    // parameterized constructor
    Book(String t, String a, int y) {
        title = t;
        author = a;
        year = y;
    }

    // display book details
    void displayInfo() {
        System.out.println("Title: " + title + 
                           ", Author: " + author + 
                           ", Year: " + year);
    }

    // check if book is modern
    void checkModern() {
        if (year >= 2000) {
            System.out.println(title + " is a modern book.");
        } else {
            System.out.println(title + " is a classic book.");
        }
    }
}

public class Activity6_2 {
    public static void main(String[] args) {

	// Default constructor with user input
        System.out.println("Creating Book 1");
        Book b1 = new Book(); // user will type input
        b1.displayInfo();
        b1.checkModern();

	// Parameterized constructors with name, author, and year
        System.out.println("\nCreating Book 2");
        Book b2 = new Book("Grokking Algorithms", "Aditya Y. Bhargava", 2015);
        b2.displayInfo();
        b2.checkModern();

        System.out.println("\nCreating Book 3 (Parameterized Constructor)");
        Book b3 = new Book("Clean Code", "Robert C. Martin", 2008);
        b3.displayInfo();
        b3.checkModern();
    }
}
