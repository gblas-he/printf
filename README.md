*Este proyecto ha sido creado como parte del currículo de 42 por gblas-he.*

## Descripción

El objetivo de este proyecto es reimplementar la función `printf` de la librería estándar de C. La función `ft_printf` debe imitar el comportamiento del `printf` original para un conjunto específico de conversiones.

Este proyecto permite trabajar con funciones variádicas, parseo de cadenas y conversión de tipos, además de reforzar la escritura en bajo nivel utilizando la función `write`.

La función tiene el siguiente prototipo:

int ft_printf(const char *format, ...);

Debe devolver el número total de caracteres impresos.

Conversiones implementadas:

- %c → carácter
- %s → string
- %p → puntero en hexadecimal
- %d → decimal
- %i → entero
- %u → entero sin signo
- %x → hexadecimal en minúsculas
- %X → hexadecimal en mayúsculas
- %% → símbolo %

---

## Instrucciones

### Compilación

El proyecto genera una librería estática llamada `libftprintf.a`.

Comandos disponibles:

make        - Compila la librería  
make clean  - Elimina los archivos objeto  
make fclean - Elimina objetos y la librería  
make re     - Recompila todo  

---

### Uso

Incluye el header en tu programa:

#include "ft_printf.h"

Ejemplo:

ft_printf("Hola %s, tienes %d años\n", "Juan", 25);

---

## Explicación y decisiones técnicas

### Funciones variádicas

Se utilizan las macros `va_list`, `va_start`, `va_arg` y `va_end` para gestionar un número variable de argumentos.

---

### Parseo del formato

El algoritmo recorre la cadena carácter por carácter:

- Si encuentra un carácter normal → se imprime directamente
- Si encuentra `%` → identifica la conversión siguiente y llama a la función correspondiente

Esto permite separar la lógica de parseo de la lógica de impresión.

---

### Estructura del código

El proyecto está dividido en:

- Función principal `ft_printf`
- Funciones específicas para cada tipo de conversión
- Funciones auxiliares para conversión de números

Esta estructura modular facilita la extensibilidad y mantenimiento del código.

---

### Conversión de datos

- Los números se convierten mediante divisiones sucesivas según su base
- Los hexadecimales usan base 16
- Los punteros se convierten a `unsigned long` y se imprimen en hexadecimal con el prefijo `0x`

---

### Contador de caracteres

Cada función de impresión devuelve el número de caracteres escritos.  
El total se acumula en `ft_printf` y se devuelve al final.

---

### Escritura

Toda la salida se realiza mediante la función `write`, ya que el uso de `printf` está prohibido.

---

## Recursos

- https://www.it.uc3m.es/pbasanta/asng/course_notes/input_output_printf_es.html
- https://www.geeksforgeeks.org/c/format-specifiers-in-c/
- man printf
- https://42-cursus.gitbook.io/guide/1-rank-01/ft_printf/variadic-functions
- https://www.geeksforgeeks.org/c/variadic-functions-in-c/
- https://stackoverflow.com/questions/32997609/extracting-type-info-from-printf-format-string
- https://stackoverflow.com/questions/50646491/how-does-printf-returns-the-count-of-the-number-of-characters-successfully-print