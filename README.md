# Intérprete de Expresiones Aritméticas en C

Este proyecto es un intérprete básico desarrollado en C. El programa es capaz de recibir expresiones matemáticas simples de suma y resta, procesarlas mediante un analizador léxico y un analizador sintáctico (parser), y devolver el resultado de la operación.
Todo esto usando métodos estándar de C, sin librerías externas.

## Requisitos

Para compilar y ejecutar este programa, necesitas tener instalado un compilador de C, como GCC.

## Instrucciones de Compilación y Ejecución

1. Compila el programa con el siguiente comando:
```bash
gcc main.c -o interpreter

```


2. Ejecuta el programa:
```bash
./interpreter

```



Una vez ejecutado, puedes introducir expresiones como `10 + 20 - 5` y presionar Enter para ver el resultado.

## Conceptos Aprendidos

A través de la implementación de este código, se han puesto en práctica los siguientes conceptos:

1. **Tokenización (Análisis Léxico):** El proceso de convertir una cadena de caracteres de entrada en una secuencia de unidades con significado llamadas "Tokens". En este caso, el programa identifica números (INT) y operadores (OP).
2. **Análisis Sintáctico (Parsing):** La lógica para verificar que la secuencia de tokens siga una estructura válida (por ejemplo, que después de un número venga un operador y luego otro número).
3. **Gestión de Caracteres en C:** El uso de funciones como `is_digit` y el manejo de espacios en blanco para limpiar la entrada.
4. **Conversión de Tipos:** El método para convertir caracteres ASCII de números a valores enteros (`c - '0'`).

## Estructura del Código

* **Estructura Token:** Define el tipo de dato y su valor asociado.
* **get_next_token:** Núcleo del lexer. Lee el texto y genera el siguiente token disponible.
* **parse:** Asegura que el token obtenido es el esperado para evitar errores de sintaxis.
* **interpret:** Coordina la lectura de la expresión y realiza los cálculos matemáticos correspondientes.

## Posibles Mejoras

* Implementar el uso de paréntesis para manejar la precedencia de operadores.
* Mejorar el manejo de errores para que el programa no finalice ante una entrada inválida, sino que permita reintentarlo.
