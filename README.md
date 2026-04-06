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

**b)** (12 pts) Escriba un fragmento de C++ con clases `Figura` (base, con al menos un método virtual puro `double area() const`) y `Circulo` (derivada). En `main`, cree un `Circolo` en el heap, guárdelo en un puntero a `Figura`, invoque `area()` a través de ese puntero y libere memoria correctamente. Explique en **una oración** por qué lo anterior es un **upcast** y por qué es seguro.

---

### Ejercicio 2 – Downcast seguro (20 pts)

**a)** (10 pts) Explique cuándo el downcast es **inseguro** si se fuerza sin comprobación. Mencione el papel de las funciones virtuales y RTTI en C++.

**b)** (10 pts) Dado un puntero `Figura* p` que en tiempo de ejecución puede apuntar a un `Circulo`, escriba el código que intente convertir a `Circulo*` usando `dynamic_cast`, verifique fallo con `nullptr` y, solo si tiene éxito, use un método exclusivo de `Circulo` (por ejemplo `double getRadio() const`).

---

### Ejercicio 3 – Dependencia mutua (15 pts)

Dos clases `A` y `B` necesitan referenciarse mutuamente en sus interfaces (por ejemplo métodos que reciben puntero al otro tipo).

**a)** (8 pts) Describa el problema de **inclusión circular** de encabezados.

**b)** (7 pts) Indique la solución estándar con **forward declaration** y en qué archivo (`.h` vs `.cpp`) suele incluirse la definición completa de la otra clase.

---

### Ejercicio 4 – OCP y KISS (25 pts)

**a)** (12 pts) Defina el **Principio Abierto/Cerrado** (Martin) en sus propias palabras y dé un ejemplo donde *violar* OCP obligaría a modificar una clase central ante cada nueva variante.

**b)** (8 pts) Explique **KISS** y **YAGNI** y cómo evitan sobreingeniería.

**c)** (5 pts) Relacione **Principio de Parnas** con “ocultar decisiones de diseño” mediante interfaces mínimas.

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

---

### Ejercicio 2 – Patrón Delegate (20 pts)

**a)** (10 pts) Explique en qué consiste el patrón **Delegate** y en qué se diferencia de heredar directamente toda la implementación.

**b)** (10 pts) Esquematice (diagrama en texto o lista de clases) un diseño donde `Reporte` delegue el destino de salida en una interfaz `DestinoSalida` con dos implementaciones: `DestinoConsola` y `DestinoArchivo`. Incluya los métodos esenciales (por ejemplo `void escribir(const string&)`).

---

### Ejercicio 3 – Excepciones (20 pts)

**a)** (10 pts) Explique la jerarquía típica `exception` / `runtime_error` / `logic_error` y cuándo usar excepciones frente a códigos de error.

**b)** (10 pts) Escriba una función `double divisionSegura(double a, double b)` que lance `invalid_argument` o `runtime_error` si `b == 0`, y un `main` o fragmento que capture y muestre el mensaje.

---

### Ejercicio 4 – LSP (20 pts)

**a)** (10 pts) Enuncie el **Principio de Sustitución de Liskov** en términos de contrato (precondiciones, postcondiciones, invariantes).

**b)** (10 pts) Describa un ejemplo de **violación** de LSP en una jerarquía (por ejemplo una derivada que refuerza precondiciones o que lanza excepciones que la base no documentaba). No copie textualmente un ejemplo de clase; invente uno coherente.

---

### Ejercicio 5 – Patrón Decorator (20 pts)

**a)** (8 pts) Explique cómo el Decorator cumple una forma de **OCP** (extender comportamiento sin modificar la clase original).

**b)** (12 pts) Diseñe en C++ (interfaces + clases) un componente `Bebida` con `double costo()` y `string descripcion()`, un `CafeSimple` concreto, y decoradores `ConLeche` y `ConAzucar` que encadenen sobre otro `Bebida*`. Incluya un pequeño ejemplo de uso que imprima costo y descripción final.

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

---

### Ejercicio 2 – Lectura de archivo de números (25 pts)

Escriba un programa o funciones que:
1. Abra un archivo de texto `datos.txt` que contiene números separados por espacios o saltos de línea.
2. Calcule **suma**, **promedio** y **cantidad** de valores leídos correctamente.
3. Si el archivo no existe o está vacío, informe el error de forma controlada (excepción o estado del flujo con mensaje claro).

---

### Ejercicio 3 – Escritura formateada (15 pts)

Usando `<iomanip>`, escriba un fragmento que imprima en consola una tabla con tres columnas: `ID`, `Nombre`, `Puntaje`, con anchos fijos y puntaje con dos decimales.

---

### Ejercicio 4 – Archivo binario (25 pts)

**a)** (15 pts) Defina una `struct` trivial `Registro` con al menos tres campos (por ejemplo `int id`, `double valor`, `char tipo`) y escriba código que guarde un arreglo o `vector` de `Registro` en un archivo **binario** y luego lo vuelva a leer, verificando que la cantidad leída coincide con la escrita.

**b)** (10 pts) Mencione un riesgo de portabilidad al compartir archivos binarios entre plataformas y cómo mitigarlo (aunque sea conceptualmente).

---

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
