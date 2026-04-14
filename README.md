# EIF204 – Programación 2 | Tres simulacros de examen (Semanas 1–5)

**Alcance temático:** Sesiones 1–10 según plan 2026: relaciones y casting, SOLID/KISS/YAGNI/Parnas, Delegate y excepciones, LSP y Decorator, manejo de flujos (texto y binario).

**Formato sugerido:** Examen escrito o mixto (teoría + código en papel o IDE sin internet, según reglamento del curso).

**Duración orientativa por simulacro:** 90–120 minutos.

**Puntaje base:** 100 puntos por simulacro.

---

# Simulacro A – Énfasis en herencia, casting y diseño básico

## Instrucciones generales
- Responda con claridad. En código, use C++ estándar (C++17 o superior si aplica).
- Donde pida código, puede ser fragmentos completos o pseudocódigo muy cercano a C++, siempre sintácticamente coherente.
- Use `using namespace std;` si lo considera adecuado para ahorrar espacio.

---

### Ejercicio 1 – Relaciones y upcast (20 pts)

**a)** (8 pts) Distinga en una tabla breve tres tipos de relación entre clases: herencia (“es-un”), composición/agregación (“tiene-un”) y dependencia (“usa-a”). Incluya un ejemplo de cada uno en el contexto de un sistema de software (no hace falta código).

    |   Herencia    Estudiante es una Persona
    |   Composicion Casa tiene Habitaciones
    |   Dependecia  Carro usa un Motor
**b)** (12 pts) Escriba un fragmento de C++ con clases `Figura` (base, con al menos un método virtual puro `double area() const`) y `Circulo` (derivada). En `main`, cree un `Circolo` en el heap, guárdelo en un puntero a `Figura`, invoque `area()` a través de ese puntero y libere memoria correctamente. Explique en **una oración** por qué lo anterior es un **upcast** y por qué es seguro.

        
---

### Ejercicio 2 – Downcast seguro (20 pts)

**a)** (10 pts) Explique cuándo el downcast es **inseguro** si se fuerza sin comprobación. Mencione el papel de las funciones virtuales y RTTI en C++.

**b)** (10 pts) Dado un puntero `Figura* p` que en tiempo de ejecución puede apuntar a un `Circulo`, escriba el código que intente convertir a `Circulo*` usando `dynamic_cast`, verifique fallo con `nullptr` y, solo si tiene éxito, use un método exclusivo de `Circulo` (por ejemplo `double getRadio() const`).

---

### Ejercicio 3 – Dependencia mutua (15 pts)

Dos clases `A` y `B` necesitan referenciarse mutuamente en sus interfaces (por ejemplo métodos que reciben puntero al otro tipo).

**a)** (8 pts) Describa el problema de **inclusión circular** de encabezados.

El problema de la inclusión circular recae en que el programa va a estar buscado una validacion de una clase y la otra. Por así decirlo A le va a pedir a B y B le va a pedir a A. Estoy provocaria que entren en un bucle del que no pueden salir

**b)** (7 pts) Indique la solución estándar con **forward declaration** y en qué archivo (`.h` vs `.cpp`) suele incluirse la definición completa de la otra clase.

La declaracion por adelantado se realiza normalmente en el .h y la declaracion completa en  el .cpp o sea #include "ClaseB.h"

---

### Ejercicio 4 – OCP y KISS (25 pts)

**a)** (12 pts) Defina el **Principio Abierto/Cerrado** (Martin) en sus propias palabras y dé un ejemplo donde *violar* OCP obligaría a modificar una clase central ante cada nueva variante.
    El principio abierto cerrado es que un programa esté abierto a ser extendido/ampliado y cerrado a las modificaciones.
    Un ejemplo de la violacion del principio ocurre cuando no se utiliza polimorfismo. Imaginemos que creamos una clase de Figura pero en  esta clase no utilizamos el polimorfismo y creamos un metodo de calcular area.
    Al no usar el polimorfismo tendriamos que modificar la clase cada vez que se agregue una nueva figura.

**b)** (8 pts) Explique **KISS** y **YAGNI** y cómo evitan sobreingeniería.
    
El principio KISS no es dice que un programa no tiene que ser innecesariamente complejo. Mantener y utilizar solo las cosas necesarias para así no sobrecargar el codigo Keep It Super Simple
Y el principio YAGNI nos insta a preguntarnos si realmente algo que hacemos es necesario para un programa, realmente vamos a utilizar algo? Nos ayuda a no agregar codigo que no sea estrictamente necesario
**c)** (5 pts) Relacione **Principio de Parnas** con “ocultar decisiones de diseño” mediante interfaces mínimas.
El principio de Parnas nos permite ocultar del usuario o de vistas no deseadas la informacion del codigo. No se debe saber lo que no este necesario conocer. Un usuario no necesita saber ni tener acceso a todo el funcionamiento de un cajero automatico, solo requiere saber cuales su saldo y poder sacarlo.

---

### Ejercicio 5 – Flujo de texto (20 pts)

Escriba una función `void numerarLineas(const string& nombreEntrada, const string& nombreSalida)` que:
- abra `nombreEntrada` para lectura de texto;
- escriba en `nombreSalida` cada línea precedida por su número (`1: ...`, `2: ...`);
- use `try/catch` y lance o capture adecuadamente si el archivo de entrada no existe o no se puede abrir.

No hace falta `main` completo, pero el código debe ser compilable con inclusiones razonables.

---

## Criterios orientativos de corrección (Simulacro A)

| Aspecto | Observación |
|--------|----------------|
| Upcast | Debe verse puntero/referencia a base apuntando a derivada y llamada polimórfica. |
| Downcast | Obligatorio `dynamic_cast` y comprobación de `nullptr`. |
| Dependencia mutua | Mención explícita de forward declaration y separación .h/.cpp. |
| Flujos | Uso correcto de `ifstream`/`ofstream`, cierre o RAII, manejo de errores. |

---

# Simulacro B – Énfasis en SOLID, Delegate, LSP y Decorator

## Instrucciones generales
- Justifique brevemente las respuestas conceptuales.
- En patrones, nombre las clases como en el enunciado o con nombres equivalentes pero consistentes.

---

### Ejercicio 1 – SOLID (resumen) (20 pts)

Enumere las cinco letras de **SOLID** y escriba **una frase** por letra definiendo la idea central. Luego elija **una** letra y ejemplifique con un contraejemplo (código o descripción) de violación.

S – Single Responsibility Principle
Una clase debe tener una sola razón para cambiar.

O – Open/Closed Principle
El código debe estar abierto a extensión, cerrado a modificación.

L – Liskov Substitution Principle
Una subclase debe poder reemplazar a su clase base sin romper el programa.

I – Interface Segregation Principle
No obligar a clases a implementar interfaces que no necesitan.

D – Dependency Inversion Principle
Depender de abstracciones, no de implementaciones concretas.

Contraejemplo:
class Reporte {
public:
void generar() { /* lógica */ }
void guardarEnArchivo() { /* archivo */ }
void enviarEmail() { /* email */ }
};

---

### Ejercicio 2 – Patrón Delegate (20 pts)

**a)** (10 pts) Explique en qué consiste el patrón **Delegate** y en qué se diferencia de heredar directamente toda la implementación.

El patrón Delegate consiste en que un objeto delegue parte de su comportamiento a otro objeto mediante composición.
Herencia: reutiliza comportamiento acoplado
Delegate: reutiliza comportamiento flexible y reemplazable

**b)** (10 pts) Esquematice (diagrama en texto o lista de clases) un diseño donde `Reporte` delegue el destino de salida en una interfaz `DestinoSalida` con dos implementaciones: `DestinoConsola` y `DestinoArchivo`. Incluya los métodos esenciales (por ejemplo `void escribir(const string&)`).

#include <iostream>
#include <fstream>
using namespace std;

class DestinoSalida {
public:
virtual void escribir(const string& texto) = 0;
virtual ~DestinoSalida() {}
};

class DestinoConsola : public DestinoSalida {
public:
void escribir(const string& texto) override {
cout << texto << endl;
}
};

class DestinoArchivo : public DestinoSalida {
private:
ofstream archivo;
public:
DestinoArchivo(string nombre) {
archivo.open(nombre);
}
void escribir(const string& texto) override {
archivo << texto << endl;
}
};

class Reporte {
private:
DestinoSalida* destino;
public:
Reporte(DestinoSalida* d) : destino(d) {}

    void generar() {
        destino->escribir("Reporte generado");
    }
};

---

### Ejercicio 3 – Excepciones (20 pts)

**a)** (10 pts) Explique la jerarquía típica `exception` / `runtime_error` / `logic_error` y cuándo usar excepciones frente a códigos de error.

exception → base general
logic_error → errores de programación (ej: argumentos inválidos)
runtime_error → errores en ejecución (ej: archivo no encontrado)

Excepciones cuando:

El error no puede manejarse localmente
Se quiere separar lógica de error

**b)** (10 pts) Escriba una función `double divisionSegura(double a, double b)` que lance `invalid_argument` o `runtime_error` si `b == 0`, y un `main` o fragmento que capture y muestre el mensaje.

#include <iostream>
#include <stdexcept>
using namespace std;

double divisionSegura(double a, double b) {
if (b == 0) {
throw invalid_argument("Division por cero");
}
return a / b;
}

int main() {
try {
cout << divisionSegura(10, 0);
} catch (const exception& e) {
cout << "Error: " << e.what() << endl;
}
}

---

### Ejercicio 4 – LSP (20 pts)

**a)** (10 pts) Enuncie el **Principio de Sustitución de Liskov** en términos de contrato (precondiciones, postcondiciones, invariantes).

Una subclase debe cumplir:

No reforzar precondiciones
No debilitar postcondiciones
Mantener invariantes

Es decir: debe comportarse como la clase base esperaba.

**b)** (10 pts) Describa un ejemplo de **violación** de LSP en una jerarquía (por ejemplo una derivada que refuerza precondiciones o que lanza excepciones que la base no documentaba). No copie textualmente un ejemplo de clase; invente uno coherente.

class Pago {
public:
virtual void procesar(double monto) {
// acepta cualquier monto positivo
}
};

class PagoCripto : public Pago {
public:
void procesar(double monto) override {
if (monto < 100) {
throw runtime_error("Minimo 100");
}
}
};

---

### Ejercicio 5 – Patrón Decorator (20 pts)

**a)** (8 pts) Explique cómo el Decorator cumple una forma de **OCP** (extender comportamiento sin modificar la clase original).

Decorator permite agregar comportamiento dinámicamente sin modificar la clase base.

Cumple OCP porque:

No se modifica CafeSimple
Se agregan nuevas clases

**b)** (12 pts) Diseñe en C++ (interfaces + clases) un componente `Bebida` con `double costo()` y `string descripcion()`, un `CafeSimple` concreto, y decoradores `ConLeche` y `ConAzucar` que encadenen sobre otro `Bebida*`. Incluya un pequeño ejemplo de uso que imprima costo y descripción final.

#include <iostream>
using namespace std;

class Bebida {
public:
virtual double costo() = 0;
virtual string descripcion() = 0;
virtual ~Bebida() {}
};

class CafeSimple : public Bebida {
public:
double costo() override { return 2.0; }
string descripcion() override { return "Cafe"; }
};

class Decorador : public Bebida {
protected:
Bebida* bebida;
public:
Decorador(Bebida* b) : bebida(b) {}
};

class ConLeche : public Decorador {
public:
ConLeche(Bebida* b) : Decorador(b) {}

    double costo() override {
        return bebida->costo() + 0.5;
    }

    string descripcion() override {
        return bebida->descripcion() + " con leche";
    }
};

class ConAzucar : public Decorador {
public:
ConAzucar(Bebida* b) : Decorador(b) {}

    double costo() override {
        return bebida->costo() + 0.2;
    }

    string descripcion() override {
        return bebida->descripcion() + " con azucar";
    }
};

// Uso
int main() {
Bebida* cafe = new CafeSimple();
cafe = new ConLeche(cafe);
cafe = new ConAzucar(cafe);

    cout << cafe->descripcion() << endl;
    cout << cafe->costo() << endl;
}

---

## Criterios orientativos de corrección (Simulacro B)

| Aspecto | Observación |
|--------|----------------|
| Delegate | Debe verse composición/agregación hacia la interfaz delegada, no solo herencia múltiple sin sentido. |
| LSP | Debe hablar de sustituibilidad y contrato, no solo “heredar mal”. |
| Decorator | Misma interfaz, composición recursiva o encadenada, delegación a componente envuelto. |

---

# Simulacro C – Énfasis integrador + flujos y binarios

## Instrucciones generales
- Puede distribuir el tiempo: ~40 % teoría, ~60 % práctica.
- Sea explícito con nombres de tipos y cabeceras (`#include`) cuando escriba código.

---

### Ejercicio 1 – Parnas y encapsulamiento (15 pts)

Explique cómo el **Principio de Parnas** reduce el acoplamiento entre módulos. Dé un ejemplo donde una clase exponga solo dos métodos públicos mientras mantiene detalles de representación en privado.

El principio de Parnas propone ocultar decisiones de diseño que pueden cambiar, reduciendo acoplamiento

class Lista {
private:
int* datos;
int tamaño;

public:
void agregar(int x);
int obtener(int i);
};

---

### Ejercicio 2 – Lectura de archivo de números (25 pts)

Escriba un programa o funciones que:
1. Abra un archivo de texto `datos.txt` que contiene números separados por espacios o saltos de línea.
2. Calcule **suma**, **promedio** y **cantidad** de valores leídos correctamente.
3. Si el archivo no existe o está vacío, informe el error de forma controlada (excepción o estado del flujo con mensaje claro).

#include <iostream>
#include <fstream>
using namespace std;

void procesarArchivo() {
ifstream archivo("datos.txt");

    if (!archivo) {
        throw runtime_error("No se pudo abrir el archivo");
    }

    double num, suma = 0;
    int count = 0;

    while (archivo >> num) {
        suma += num;
        count++;
    }

    if (count == 0) {
        throw runtime_error("Archivo vacio");
    }

    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << suma / count << endl;
    cout << "Cantidad: " << count << endl;
}

---

### Ejercicio 3 – Escritura formateada (15 pts)

Usando `<iomanip>`, escriba un fragmento que imprima en consola una tabla con tres columnas: `ID`, `Nombre`, `Puntaje`, con anchos fijos y puntaje con dos decimales.

#include <iostream>
#include <iomanip>
using namespace std;

cout << setw(5) << "ID"
<< setw(15) << "Nombre"
<< setw(10) << "Puntaje" << endl;

cout << setw(5) << 1
<< setw(15) << "Ana"
<< setw(10) << fixed << setprecision(2) << 95.5 << endl;

---

### Ejercicio 4 – Archivo binario (25 pts)

**a)** (15 pts) Defina una `struct` trivial `Registro` con al menos tres campos (por ejemplo `int id`, `double valor`, `char tipo`) y escriba código que guarde un arreglo o `vector` de `Registro` en un archivo **binario** y luego lo vuelva a leer, verificando que la cantidad leída coincide con la escrita.

#include <fstream>
using namespace std;

struct Registro {
int id;
double valor;
char tipo;
};

void guardar() {
ofstream out("data.bin", ios::binary);

    Registro r[2] = {{1, 10.5, 'A'}, {2, 20.5, 'B'}};

    out.write(reinterpret_cast<char*>(r), sizeof(r));
}

void leer() {
ifstream in("data.bin", ios::binary);

    Registro r[2];

    in.read(reinterpret_cast<char*>(r), sizeof(r));
}

**b)** (10 pts) Mencione un riesgo de portabilidad al compartir archivos binarios entre plataformas y cómo mitigarlo (aunque sea conceptualmente).

Problema: Diferente tamaño de tipos o endianess

Solución: Usar formato estándar (JSON/binario estructurado) o serialización controlada


### Ejercicio 5 – Integración corta (20 pts)

En máximo **15 líneas** de explicación (sin código obligatorio), relacione: **upcast**, **polimorfismo**, **Decorator** y **flujo de salida a archivo**, como si fueran partes de un mismo sistema que genera reportes de objetos heterogéneos.

---

## Criterios orientativos de corrección (Simulacro C)

| Aspecto | Observación |
|--------|----------------|
| Texto | Bucle de lectura, comprobación `fail()/eof()` o excepciones, no asumir archivo perfecto. |
| Binario | `ios::binary`, `write`/`read` con `reinterpret_cast` o equivalente correcto, tamaños coherentes. |
| Integración | Debe conectar ideas, no listar definiciones sueltas. |

---

## Notas para el docente

- Los tres simulacros cubren el mismo bloque (semanas 1–5) con **distribución distinta de peso**; puede usarse uno como diagnóstico, otro como repaso pre-parcial y otro como tarea en casa.
- Si el examen real será solo sobre un subconjunto, puede **recortar** un ejercicio completo y renormalizar a 100 puntos.
- Para alinear con honor académico, indique explícitamente si se permite o no material externo y si los simulacros son **individuales**.

---

**Referencias (APA)** – coherente con el plan del curso: Freeman y Robson (2020); Savitch (2018).
