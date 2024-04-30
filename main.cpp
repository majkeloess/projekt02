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

  IKsiazka *ksiazka = Ksiazka::create("W pustyni i w puszczy", "Henryk Sienkiewicz", 1, "Przygodowa", 5);
  IKsiazka *czasopismo = Czasopismo::create("National Geographic", "John Doe", 2, "Przyroda", 7);
  IKsiazka *komiks = Komiks::create("Batman", "Bob Kane", 3, "Superbohaterowie", 9);

  library.addMaterial(ksiazka);
  library.addMaterial(czasopismo);
  library.addMaterial(komiks);

  User user1("Jan Piotrowski");
  User user2("Anna Pietruszka");

  // Wypożycz książki przez użytkowników
  library.borrowBook("Batman", user1);
  library.borrowBook("Wiedźmin", user2); // Próba wypożyczenia nieistniejącej książki
  library.borrowBook("Batman", user2);   // Próba wypożyczenia niedostępnej już książki
  library.borrowBook("W pustyni i w puszczy", user2);

  // Wyświetl informacje o wypożyczonych książkach
  std::cout << "\nKonto użytkowinka " << user1.getName() << ":\n";
  user1.displayBorrowedBooks();

  std::cout << "\nKonto użytkowinka " << user2.getName() << ":\n";
  user2.displayBorrowedBooks();

  // Zwróć książki
  library.returnBook("W pustyni i w puszczy", user1);
  library.returnBook("Batman", user1);
  library.returnBook("W pustyni i w puszczy", user2);

  // Wyświetl informacje o wszystkich książkach w bibliotece
  std::cout << "\nWszystkie książki w bibliotece:\n";
  library.displayAllBooks();

  return 0;
}

// Spodziewany output
/*

Użytkownik Jan Piotrowski wypożyczył książkę: Batman
Przepraszamy, książka "Wiedźmin" jest już wypożyczona lub nie istnieje.
Przepraszamy, książka "Batman" jest już wypożyczona lub nie istnieje.
Użytkownik Anna Pietruszka wypożyczył książkę: W pustyni i w puszczy

Konto użytkowinka Jan Piotrowski:
Lista wypożyczonych książek przez użytkownika:
Tytuł: Batman

Konto użytkowinka Anna Pietruszka:
Lista wypożyczonych książek przez użytkownika:
Tytuł: W pustyni i w puszczy

Przepraszamy, książka W pustyni i w puszczy nie została wypożyczona przez tego użytkownika lub nie istnieje.
Użytkownik Jan Piotrowski zwrócił książkę: Batman
Użytkownik Anna Pietruszka zwrócił książkę: W pustyni i w puszczy

Wszystkie książki w bibliotece:

Lista książek w bibliotece:
Tytuł: W pustyni i w puszczy
Autor: Henryk Sienkiewicz
Id ksiazki: 1
Gatunek: Przygodowa
Na półce:  5
Status: Dostępny

Tytuł: National Geographic
Autor: John Doe
Id ksiazki: 2
Gatunek: Przyroda
Na półce:  7
Status: Dostępny

Tytuł: Batman
Autor: Bob Kane
Id ksiazki: 3
Gatunek: Superbohaterowie
Na półce: 9
Status: Dostępny

*/