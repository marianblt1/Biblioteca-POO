CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRCS = main.cpp Carte.cpp CarteFizica.cpp CarteFictiune.cpp CarteTehnica.cpp \
       CarteDigitala.cpp Revista.cpp Utilizator.cpp UtilizatorStudent.cpp \
       UtilizatorElev.cpp UtilizatorAdult.cpp UtilizatorProfesor.cpp \
       UtilizatorPensionar.cpp UtilizatorCercetator.cpp Biblioteca.cpp

TARGET = biblioteca

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
