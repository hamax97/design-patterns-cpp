#include <iostream>

using namespace std;

struct Document;

// struct IMachine {
//   virtual void print(Document& doc) = 0;
//   virtual void scan(Document& doc) = 0;
//   virtual void fax(Document& doc) = 0;
// };

// /*
//  * The interface IMachine would be ok if I had a multifunctional printer.
//  * So in this case, it works.
//  */
// struct MultiFunctionalPrinter : IMachine {
//   void print(Document& doc) override {
//     // OK.
//   }
//   void scan(Document& doc) override {
//     // OK.
//   }
//   void fax(Document& doc) override {
//     // OK.
//   }
// };

// /*
//  * BUT, what if I have only a scanner, or only a printer.
//  * It is really bad to say that your scanner can print when it cannot.
//  */
// struct Scanner : IMachine {
//   void print(Document& doc) override {
//     // NOT OK.
//   }
//   void scan(Document& doc) override {
//     // This function is ok.
//   }
//   void fax(Document& doc) override {
//     // NOT OK.
//   }
// };

/*
 * So, HOW TO SOLVE THIS ISSUE?
 */

struct IPrinter {
  virtual void print(Document& doc) = 0;
};

struct IScanner {
  virtual void scan(Document& doc) = 0;
};

struct IFax {
  virtual void fax(Document& doc) = 0;
};

/*
 * Then, if you just need a printer ...
 */
struct Printer : IPrinter {
  void print(Document& doc) override {}
};

struct Scanner : IScanner {
  void scan(Document& doc) override {}
};

/*
 * What if you need a more complicated machine.
 */
struct IMachine : IPrinter, IScanner {
  // You don't need bodies, you can keep IMachine abstract.
};

struct Machine : IMachine {
  // One way is to implement your machine in terms of your already created
  // objects.
  IPrinter& printer;
  IScanner& scanner;

  Machine(IPrinter& printer, IScanner& scanner) :
    printer(printer), scanner(scanner) {}

  void print(Document& doc) override {
    printer.print(doc);
  }
  void scan(Document& doc) override {
    scanner.scan(doc);
  }
};
int main() {}
