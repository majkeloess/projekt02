#include <iostream>
#include "IKsiazka.h"
#include "Ksiazka.h"
#include "Czasopismo.h"
#include "Komiks.h"
#include "Library.h"
#include "User.h"

int main()
{
  Library library;
  IKsiazka *ksiazka_1 = Ksiazka::create("Język C++", "Stephen Prata", 1, "Naukowa", 3);
  IKsiazka *ksiazka_2 = Ksiazka::create("1984", "George Orwell", 1, "Fantastyka", 5);
  IKsiazka *czasopismo = Czasopismo::create("National Geographic", "John Doe", 2, "Przyroda", 7);
  IKsiazka *komiks = Komiks::create("Batman", "Bob Kane", 3, "Superbohaterowie", 9);

  library.addMaterial(ksiazka_1);
  library.addMaterial(ksiazka_2);
  library.addMaterial(czasopismo);
  library.addMaterial(komiks);

  User user1("Grzegorz Brzęczyszczykiewicz");
  User user2("Arnold Schwarzenegger");

  // Wypożycz książki przez użytkowników
  library.borrowBook("Batman", user1);
  library.borrowBook("Folkwark Zwierzęcy", user2); // Próba wypożyczenia nieistniejącej książki
  library.borrowBook("Batman", user2);   // Próba wypożyczenia niedostępnej już książki
  library.borrowBook("1984", user2);

  // Wyświetl informacje o wypożyczonych książkach
  std::cout << "\nKonto użytkowinka " << user1.getName() << ":\n";
  user1.displayBorrowedBooks();

  std::cout << "\nKonto użytkowinka " << user2.getName() << ":\n";
  user2.displayBorrowedBooks();

  // Zwróć książki
  library.returnBook("1984", user1);
  library.returnBook("Batman", user1);
  library.returnBook("1984", user2);

  // Wyświetl informacje o wszystkich książkach w bibliotece
  std::cout << "\nWszystkie książki w bibliotece:\n";
  library.displayAllBooks();

  return 0;
}
