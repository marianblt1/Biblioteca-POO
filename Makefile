CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRCS = main.cpp Carte.cpp CarteFizica.cpp CarteFictiune.cpp CarteTehnica.cpp CarteDigitala.cpp Revista.cpp Utilizator.cpp UtilizatorStudent.cpp UtilizatorElev.cpp UtilizatorAdult.cpp UtilizatorProfesor.cpp UtilizatorPensionar.cpp UtilizatorCercetator.cpp Biblioteca.cpp Meniu.cpp Autentificare.cpp Camera.cpp Cladire.cpp

TEST_SRCS = Teste.cpp Carte.cpp CarteFizica.cpp CarteFictiune.cpp CarteTehnica.cpp CarteDigitala.cpp Revista.cpp Utilizator.cpp UtilizatorStudent.cpp UtilizatorElev.cpp UtilizatorAdult.cpp UtilizatorProfesor.cpp UtilizatorPensionar.cpp UtilizatorCercetator.cpp Biblioteca.cpp Camera.cpp Cladire.cpp

TARGET = biblioteca
TEST_TARGET = teste

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

$(TEST_TARGET): $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRCS)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
