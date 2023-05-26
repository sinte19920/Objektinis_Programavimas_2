# v1.2

Nuo šios versijos yra pritaikyta "rule of five" "Studentas" klasei, aprašytoje funkcijos.h faile.

## Rule of five:

- Default constructor: Studentas()
- Copy constructor: Studentas(const Studentas& other)
- Move constructor: Studentas(Studentas&& other)
- Copy assignment constructor: Studentas& operator=(const Studentas& other)
- Move assignment constructor: Studentas& operator=(Studentas&& other)

Nuo šios versijos pridėtas ir std::ostream& operator<< operatorius, kad būtų palengvintas duomenų išvedimas.
