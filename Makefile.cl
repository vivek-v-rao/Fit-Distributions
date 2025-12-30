CXX = cl
CXXFLAGS = /std:c++20 /O2 /W4 /EHsc
TARGET = fit_distributions.exe
SOURCES = main.cpp \
          stats.cpp \
          normal.cpp \
          laplace.cpp \
          hyperbolic_sech.cpp \
          logistic.cpp \
          model_registry.cpp \
          simulation.cpp \
          student_t.cpp \
          generalized_error.cpp \
          symmetric_hyperbolic.cpp
OBJECTS = $(SOURCES:.cpp=.obj)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	link $(OBJECTS) /OUT:$(TARGET)

%.obj: %.cpp
	$(CXX) $(CXXFLAGS) /c $< /Fo$@

clean:
	del /Q $(OBJECTS) $(TARGET) 2>NUL || cmd /c exit 0
